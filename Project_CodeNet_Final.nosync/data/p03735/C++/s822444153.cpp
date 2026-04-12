#include <bits/stdc++.h>
 
using namespace std;
#define int long long


 const int MAX = 1001;
const int MOD = 1000000007;



signed main(){
 
   int n;
   cin>>n;
   int x,y,ymax=0,xmin=MOD,xmax=0,ymin=MOD;
  pair<int,int> p[n];
   for(int i=0;i<n;i++){
       cin>>x>>y;
        if(x>y)swap(x,y);
        if(xmin>x)xmin=x;
        if(xmax<x)xmax=x;
        if(ymax<y)ymax=y;
        if(ymin>y)ymin=y;
        p[i]=make_pair(x,y);

   }
   sort(p,p+n);
   int ans=p[n-1].first-p[0].first;
   int c1=MOD,c2=p[n-1].first;
   for(int i=1;i<n;i++){
       c1=min(p[i-1].second,c1);
       c2=max(c2,p[i-1].second);
       ans=min(ans,-min(p[i].first,c1)+c2);
   }
   cout<<min((xmax-xmin)*(ymax-ymin),(ymax-xmin)*ans);
    return 0;
}