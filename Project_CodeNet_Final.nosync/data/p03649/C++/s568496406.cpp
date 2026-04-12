#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
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
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
    lint N;
    cin >> N;
    lint a[N];
    rep(i,N) cin >> a[i];
    sort(a,a+N);
    rep(i,N) a[i]-=N-1;
    lint ans=0;
    while(true){
        rep(i,N){
            lint plus=max(0LL,(a[i]+N-1)/N);
            ans+=plus;
            a[i]-=plus*N;
            rep(j,N) if(j!=i) a[j]+=plus;
        }
        bool check=true;
        rep(i,N) if(a[i]>0) check=false;
        if(check) break;
    }
    cout << ans << endl;
}