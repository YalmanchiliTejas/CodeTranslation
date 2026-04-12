#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};
//vector<int> bucket[MAX_N/1000];

int main(void){
    lint N,X,M;
    cin >> N >> X >> M;
    lint las[M]={};
    rep(i,M) las[i]=-1;
    lint now=X,cnt=1;
    lint cb;
    lint syuki;
    las[X]=0;
    while(true){
        now=(now*now)%M;
        if(las[now]!=-1){
            syuki=cnt-las[now];
            cb=now;
            break;
        }
        else las[now]=cnt;
        cnt++;
    }
    lint ans=0;
    lint sim=X;
    lint rem=N;
    while(sim!=cb){
        ans+=sim;
        sim=(sim*sim)%M;
        rem--;
        if(rem==0) break;
    }
    sim=(sim*sim)%M;
    lint one=sim;
    while(sim!=cb){
        sim=(sim*sim)%M;
        one+=sim;
    }
    lint need=rem/syuki;
    ans+=need*one;
    rem%=syuki;
    rep(i,rem){
        ans+=sim;
        sim=(sim*sim)%M;
    }
    cout << ans << endl;
}