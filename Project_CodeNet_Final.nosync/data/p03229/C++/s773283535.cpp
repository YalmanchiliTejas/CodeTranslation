#include<iostream>
#include<cstring>
using namespace std;
void combsort(long A[100010],int);

int main (){
  int N;
  long X;
  long A[100010];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  combsort(A,N);
  if (N%2==0)
  {
    X=0;
    for(int i=0;i<N/2-1;i++){
      X-=(A[i]*2);
    }
    for(int i=N/2+1;i<N;i++){
      X+=(A[i]*2);
    }
    X+=(A[N/2]);
    X-=(A[N/2-1]);
  }else{
    X=0;
    for(int i=0;i<N/2-1;i++){
      X-=(A[i]*2);
    }
    for(int i=N/2+2;i<N;i++){
      X+=(A[i]*2);
    }

    if (A[N/2+1]*2-A[N/2]-A[N/2-1]>A[N/2+1]+A[N/2]-A[N/2-1]*2)
    {
      X+=(A[N/2+1]*2-A[N/2]-A[N/2-1]);
    }else{
      X+=(A[N/2+1]+A[N/2]-A[N/2-1]*2);
    }
  }
  cout <<X <<endl;
}


void combsort(long A[100010],int N){
  int h=N*10/13;
  while (h>=1){
    int noswap=1;
    for (int i=0;i+h<N;i++){
      if (A[i]>A[i+h]){
        long a;
        a=A[i];A[i]=A[i+h];A[i+h]=a;
        noswap=0;
      }
    }
    if (h==1&&noswap){break;}
    h=h*10/13;
  }
}