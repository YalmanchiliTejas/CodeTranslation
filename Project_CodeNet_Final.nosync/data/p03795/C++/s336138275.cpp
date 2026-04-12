#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define ALL(v)      (v).begin(),(v).end()
#define BIT(n)      (1LL<<(n))
#define IN(x,l,r)   ((l)<=(x)&&(x)<=(r))
#define LEN(s)      (string(s)).length()
#define NPOS        string::npos
#define SHOW(x)     cout<<#x<<" = "<<x<<endl
#define SORT(v)     sort(ALL(v))
#define SZ(v)       (ll)(v).size()
#define UNIQ(v)     SORT(v);(v).erase(unique(ALL(v)),(v).end())
#define PERM(v)     for(bool p=1;p;p=next_permutation(ALL(v)))
#define PQ(T)       priority_queue<T,vector<T>,greater<T>>

template<class T>string join(const vector<T>& v,string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(LEN(d));}

template<class T>ostream& operator<<(ostream& s,const vector<T>& v)
{s<<"{";if(SZ(v))s<<join(v,", ");s<<"}";return s;}

template<class T>bool contain(const string& s,const T& v)
{return s.find(v)!=NPOS;}

template<class T,class U>string& replace(string& s,const T& f,const U& t)
{for(auto p=s.find(f);p!=NPOS;p=s.find(f,p+LEN(t)))s.replace(p,LEN(f),t);}

const ll INF = 1e15;
const ll MOD = 1e9+7;
const double EPS = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ll N; cin >> N;
    
    ll x = 800 * N;
    ll y = 200 * (N / 15);
    
    cout << x - y << endl;
    
    return 0;
}
