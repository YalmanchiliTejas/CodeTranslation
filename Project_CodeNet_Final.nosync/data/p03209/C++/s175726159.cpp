#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define int long long

int size[55];
int cntP[55];

int rec(int N,int X) // [0,X)
{  
   assert(X>0);
   if(X==size[N]) return cntP[N];

   int res=0;
   if(X>=2){
      res+=rec(N-1,min(size[N-1], X-1));
   }
   if(X>=size[N-1]+2){
      res++;
   }
   if(X>=size[N-1]+3){
      res+=rec(N-1,min(size[N-1],X-(size[N-1]+2)));
   }
   return res;
}

signed main()
{
   int N,X; cin>>N>>X;
   size[0]=1;
   cntP[0]=1;
   REP(i,N){
      size[i+1]=size[i]*2+3;
      cntP[i+1]=cntP[i]*2+1;
   }
   cout<<rec(N,X)<<endl;
}
