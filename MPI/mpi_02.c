#include "mpi.h"
#include <stdio.h>

   main(int argc, char *argv[])  {
   int numtasks, rank, dest, source, rc, count, tag=1;  
   char inmsg, outmsg='x';
   MPI_Status Stat;   // required variable for receive routines

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   right = (rank + 1) % numtasks;
   left = rank - 1;
    if (left < 0)
        left = numtasks - 1;

    MPI_Sendrecv(&outmsg, 1, MPI_CHAR, left, tag, &inmsg, 1, MPI_CHAR, right, tag, MPI_COMM_WORLD, &status);

   // query recieve Stat variable and print message details
   MPI_Get_count(&Stat, MPI_CHAR, &count);
   printf("Task %d: Received %d char(s) from task %d with tag %d \n",
          rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);

   MPI_Finalize();
   }

