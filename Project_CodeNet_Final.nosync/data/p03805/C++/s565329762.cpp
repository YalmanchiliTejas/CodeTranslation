#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define crep(i) for(char i='a';i<='z';i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define ALL(x) (x).begin(),(x).end()
int ctoi(const char c){
    if('0' <= c && c <= '9') return (c-'0');
    return -1;
}
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

ll T=0,N;
vector<vector<ll>> V(17);

void dfs(ll X,ll rt[],ll C){
    rt[X]=1;
    C++;
    if(C==N){
        T++;
    }
    else{
        rep(i,V[X].size()){
            if(rt[V[X][i]]==0){
                dfs(V[X][i],rt,C);
            }
        }
    }
    rt[X]=0;
}

int main(){
    ll M,A,B;
    ll rt[10];
    rep(i,10){
        rt[i]=0;
    }
    cin >> N >> M;
    rep(i,M){
        cin >> A >> B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    dfs(1LL,rt,0LL);
    cout << T << endl;
}