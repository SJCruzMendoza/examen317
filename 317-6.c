#define MSG_DATA 101
#define MSG_RESULT 102
#include <mpi.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]){
    int rank,size;int i;int fib1[200],fib2[200],fib3[200];
    MPI_Status stat;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(rank==0){
        MPI_Recv(fib1,10,MPI_INT,1,MSG_RESULT,MPI_COMM_WORLD,&stat);
        MPI_Recv(fib2,10,MPI_INT,2,MSG_RESULT,MPI_COMM_WORLD,&stat);
        MPI_Recv(fib3,10,MPI_INT,3,MSG_RESULT,MPI_COMM_WORLD,&stat);
        for(i=0; i<10; i++)printf("%d\t",fib1[i]);
        for(i=0; i<10; i++)printf("%d\t",fib2[i]);
        for(i=0; i<10; i++)printf("%d\t",fib3[i]);}
        if(rank==1){
            fib1[0]=0;fib1[1]=1;
            for(i=2; i<=10; i++){fib1[i]=fib1[i-1]+fib1[i-2];}
            MPI_Send(fib1,10,MPI_INT,0,MSG_RESULT,MPI_COMM_WORLD);}
            if(rank==2){
                fib2[0]=(pow((1+sqrt(5))/2,10) - pow((1-sqrt(5))/2,10))/sqrt(5);fib2[1]=(pow((1+sqrt(5))/2,11) - pow((1-sqrt(5))/2,11))/sqrt(5);for(i=2;i<10; i++){
fib2[i]=fib2[i-1]+fib2[i-2];}
MPI_Send(fib2,10,MPI_INT,0,MSG_RESULT,MPI_COMM_WORLD);}
if(rank==3){fib3[0]=(pow((1+sqrt(5))/2,20) - pow((1-sqrt(5))/2,20))/sqrt(5);fib3[1]=(pow((1+sqrt(5))/2,21) - pow((1-sqrt(5))/2,21))/sqrt(5);for(i=2; i<=10; i++){fib3[i]=fib3[i-1]+fib3[i-2];}
MPI_Send(fib3,10,MPI_INT,0,MSG_RESULT,MPI_COMM_WORLD);}
MPI_Finalize();
return 0;
}