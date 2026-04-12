#include<bits/stdc++.h>
using namespace std;
#define int long long

int N,a[100];

bool check(int k)
{
   int sum=0;
   for(int i=0;i<N;i++){
      sum+=a[i];
      if(sum<k) return false;
      sum-=k;
   }
   return true;
}


signed main()
{
   cin>>N;
   for(int i=0;i<N;i++){
      cin>>a[i];
   }

   int ok=1,ng=1000;
   while(ng-ok>1){
      int mid=(ok+ng)/2;
      if(check(mid)) ok=mid;
      else ng=mid;
   }
   cout<<ok<<endl;
}


