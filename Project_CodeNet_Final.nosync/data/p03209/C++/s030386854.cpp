#include <bits/stdc++.h>
using namespace std;
const int sz=55;
int n;
long long x;
long long l[sz];
long long v[sz];

long long solve(int level,long long pos){
    if(!pos) return !level;
    if(pos==l[level]-1) return v[level];
    long long mid=l[level]>>1;
    if(pos==mid) return v[level-1]+1;
    else if(pos<mid) return solve(level-1,pos-1);
    return 1+v[level-1]+solve(level-1,pos-mid-1);
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    l[0]=1;
    v[0]=1;
    for(int i=1;i<=50;i++){
        l[i]=2*l[i-1]+3;
        v[i]=2*v[i-1]+1;
    }
    scanf("%d %lld",&n,&x);
    x--;
    printf("%lld",solve(n,x));
    return 0;
}
