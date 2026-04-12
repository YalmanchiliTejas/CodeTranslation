#include <iostream>

using namespace std;

int main()
{
   int N;
   cin>>N;
   int bill=800*N;
   while(N>=15){
       bill=bill-200;
       N=N-15;
   }
   
   cout<<bill<<endl;
   return 0;
}