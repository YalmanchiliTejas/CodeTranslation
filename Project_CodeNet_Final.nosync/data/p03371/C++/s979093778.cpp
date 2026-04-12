#include <bits/stdc++.h>
using namespace std;

int main()
{ 
   int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;
   int ans=2*c*max(x,y);
   for(int i=0;i<=max(x,y);i++){
       int cost=2*c*i+a*max(0,x-i)+b*max(0,y-i);
       ans=min(ans,cost);
   }
   
   cout<<ans<<endl;

   
}