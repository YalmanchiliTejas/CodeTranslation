#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define mp make_pair
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using ll = long long;
using namespace std;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N,K;
int main(){
    cin >> N >> K;
    long ans = 0;
    rep1(b,N) ans += (N/b)*max(0,(b-K)) + max(0,(N%b-K+1));
    if(K==0) ans -= N;
    cout << ans << endl;
}