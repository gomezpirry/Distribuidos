#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
        int my_rank, p, count, tag = 1;
        char inmsg[20];
        char outmsg[20];
        char omsg[100];
        char msg[100];
        MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &p);
        if (my_rank == 0) {
                strcpy(inmsg, "Hello ");
                MPI_Send(inmsg, strlen(inmsg) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
                MPI_Recv(omsg, 20, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status);
                printf("Mensaje Recibido: %s\n", omsg);
} else if (my_rank == 1) {

				//Si se interambian las funciones Recv y Send se genera un abrazo mrotal 
				// ya que el rank 0 y el rank 1 estarian haciendo operaciones de Envio de mensajes
                MPI_Recv(outmsg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
                strcpy(msg, outmsg );

                strcat(msg, " Mundo");
                MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 0, tag, MPI_COMM_WORLD);

        }
       printf("Task %d: Received  char(s) from task %d with tag %d \n",
          my_rank,  status.MPI_SOURCE, status.MPI_TAG);
        MPI_Finalize();
}

