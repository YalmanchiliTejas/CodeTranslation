#include<bits/stdc++.h>
#define LL long long
#define clr(x,y) memset(x,y,sizeof(x))
#define FOR(x,l,r) for(int x=l,x##_=r;x<=x##_;x++)
#define FR(x,l,r) for(int x=l,x##_=r;x<x##_;x++)
#define DOR(x,r,l) for(int x=r,x##_=l;x>=x##_;x--)
using namespace std;
const int N=200005;
int n,m;
int A[N],B[N],C[N];
void Add(int x,int d){
    while(x){
        C[x]=max(C[x],d);
        x&=x-1;
    }
}
int query(int x){
    int res=0;
    while(x<=m){
        res=max(res,C[x]);
        x+=x&-x;
    }return res;
}
int main(){
	cin>>n;
    FOR(i,1,n)scanf("%d",A+i),B[i]=A[i];
    sort(B+1,B+n+1);
    m=unique(B+1,B+n+1)-B-1;
    FOR(i,1,n)A[i]=lower_bound(B+1,B+m+1,A[i])-B;
    int ans=0,c=0;
    FOR(i,1,n){
        Add(A[i],c=query(A[i])+1);
        ans=max(ans,c);
    }cout<<ans;
    return 0;
}
