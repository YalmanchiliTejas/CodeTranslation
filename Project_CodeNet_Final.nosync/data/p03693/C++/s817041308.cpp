#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30
#define LINF 1ll<<60ll
#define MOD 1000000007
#define pb(a) push_back(a)
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vi>
#define P pair<int,int>
#define all(vec) (vec.begin()),(vec.end())
typedef long long ll;
typedef unsigned long long ull;
#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x
#define bit(n) (1<<(n))

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;++i)
#define FORVEC(i, v) for(int i = 0;i < sz(v);++i)

template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

#define fil0(i,n) cout<<swet(n)<<setfill('0')<<i<<resetiosflags(ios_base::floatfield)
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define yes(n) cout<<((n)?"yes":"no")<<endl
#define possible(n) cout<<((n)?"possible":"impossible")<<endl
#define Possible(n) cout<<((n)?"Possible":"Impossible")<<endl


int main(){
    int r,g,b;
    cin>>r>>g>>b;
    YES(!((g*10+b)%4));
    return 0;
}
