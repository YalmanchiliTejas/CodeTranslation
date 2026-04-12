 #include <cstdio>
 using namespace std;
 int main(void){
     int N=0;
     int x,y=0;
     scanf("%d",&N);
     x=N*800;
     y=N/15;
     y*=200;
     printf("%d\n",x-y);
     return 0;
 }