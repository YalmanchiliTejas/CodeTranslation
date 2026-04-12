#include <bits/stdc++.h>

using namespace std;

#define fr(i,s,e) for(i=s;i<e;i++)

int main() {
    int res=0,mx,mn=INT_MAX;
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    res=(a*x)+(b*y);
    mn=min(mn,res);
    mx=max(x,y);
    res=2*mx*c;
    mn=min(mn,res);
    if(x<y){
        res=(c*2*x)+(b*(y-x));
        mn=min(mn,res);}
    if(y<x){
        res=(c*2*y)+(a*(x-y));
        mn=min(mn,res);}
    cout<<mn;
return 0;
}
