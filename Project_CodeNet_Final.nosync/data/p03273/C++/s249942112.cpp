#include <iostream>
#include<time.h>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include<cassert>
#include<cctype>
#include<iterator>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1<<30
#define INFTY 1000000000000000001LL
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
// g++ -o a a.cpp -Wall -lm -std=c++14

int h,w;
char m[101][101];
int main(){
    cin>>h>>w;
    rep(i,h)rep(j,w)cin>>m[i][j];
    bool W[100];
    bool H[100];
    memset(W,0,sizeof(W));
    memset(H,0,sizeof(H));
    rep(i,h){
        int cn=0;
    rep(j,w){
        if(m[i][j]=='.')cn++;
    }
    if(cn==w){
        W[i]=1;
        }
    }
    //cout<<"now:"<<W[1]<<endl;
    
    rep(j,w){
        int cnt=0;
        rep(i,h){
            if(m[i][j]=='.')cnt++;
        }
        if(cnt==h)H[j]=1;
    }
    
//cout<<"then:"<<W[1]<<endl;
    
    rep(i,h){
        rep(j,w){
        if(W[i]==1 || H[j]==1)continue;
        cout<<m[i][j];
    }
    if(W[i]!=1)cout<<endl;
    }
    cout<<endl;
    
}