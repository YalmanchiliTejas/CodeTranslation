#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX=200001;
int fac[MAX],finv[MAX],inv[MAX];
int A[50],P[50];

int saiki(int N,int x){
    if(N==0)return (x<=0?0:1);
    if(x<=(1+A[N-1]))return saiki(N-1,x-1);
    return P[N-1]+1+saiki(N-1,x-2-A[N-1]);
}

signed main(){
    int N,X;cin>>N>>X;
    REP(i,50){
        if(i==0){
            A[i]=P[i]=1;
        }
        else{
            A[i]=2*A[i-1]+3;
            P[i]=2*P[i-1]+1;
        }
    }
    cout<<saiki(N,X)<<endl;
}
