
#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair

#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define dump(x)  cerr << #x << " = " << (x) << endl
#define ALL(t) (t).begin(),(t).end()

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    if(n > m){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
    return 0;
}
