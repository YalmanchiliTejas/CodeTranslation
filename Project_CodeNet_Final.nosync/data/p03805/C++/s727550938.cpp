#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
const int MOD=1000000007;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

set<int> edge[10];

int main(void){
    int N,M;
    cin >> N >> M;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--,b--;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    int A[N];
    int ans=0;
    rep(i,N) A[i]=i;
    do{
        if(A[0]!=0) break;
        bool reach[N]={};
        bool che=true;
        rep(i,N-1){
            if(!edge[A[i]].count(A[i+1])) che=false;
        }
        if(che) ans++;
    }while(next_permutation(A,A+N));
    cout << ans << endl;
}