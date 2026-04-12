#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
typedef pair<ll,ll> pairs;
vector<pairs> p;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
#define MAX_N 100100
bool x[MAX_N];
ll num[MAX_N];
ll fibl[MAX_N]={0};
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll fib(ll a){
    if (fibl[a]!=0)return fibl[a];
    if (a==0){
        return 0;
    }else if (a==1){
        return 1;
    }
    return fibl[a]=fib(a-1)+fib(a-2);
}
 
ll eratosthenes(ll n) {
    int p = 0;
    for (ll i=0; i<=n; ++i) x[i] = true;
    x[0] = x[1] = false;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            p++;
            for(int j=2*i; j<=n; j+=i) x[j] = false;
        }
        
        num[i] = p;
    }
    return p;
}
 
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}
 
ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

ll ans=0;
bool graph[9][9];
void serch(ll v,ll n,bool visited[]){
    bool all=true;
    for (ll i=0;i<n;i++){
        if (!visited[i]){
            all=false;
        }
    }
    if (all){
        ans++;
    }
    for (ll i=0;i<n;i++){
        if (graph[v][i] and !visited[i]){
            visited[i]=true;
            serch(i,n,visited);
            visited[i]=false;
        }
    }
}

int main(){
    for (ll i=0;i<8;i++){
        fill(graph[i],graph[i]+9,false);
    }
    ll n,m;
    cin >> n >> m;
    for (ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        graph[a-1][b-1]=true;
        graph[b-1][a-1]=true;
    }
    bool  visited[n];
    fill(visited,visited+n,false);
    visited[0]=true;
    serch(0,n,visited);
    cout << ans << endl;
    return 0;
}
