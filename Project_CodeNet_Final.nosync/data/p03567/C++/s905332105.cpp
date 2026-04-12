#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair<ll, ll>;

#define FOR(i,a,b)      for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b)     for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)        FOR(i,0,n)
#define RREP(i,n)       RFOR(i,n,0)
#define ALL(v)          (v).begin(),(v).end()
#define BIT(n)          (1LL<<(n))
#define IN(x,l,r)       ((l)<=(x)&&(x)<=(r))
#define INCLUDE(s,v)    (s.find(v)!=string::npos)
#define LEN(s)          (string(s)).length()
#define SHOW(x)         cout<<#x<<" = "<<x<<endl
#define SORT(v)         sort(ALL(v))
#define SZ(v)           (ll)(v).size()
#define UNIQ(v)         SORT(v);(v).erase(unique(ALL(v)),(v).end())
#define PERM(v)         for(bool p=1;p;p=next_permutation(ALL(v)))
#define PQ(T)           priority_queue<T,vector<T>,greater<T>>
#define REPLACE(s,f,t)  for(auto p=s.find(f);p!=string::npos;p=s.find(f,p+LEN(t)))s.replace(p,LEN(f),t);

template<class T>string join(const vector<T>& v,string d=" ") {stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(LEN(d));}
template<class T>ostream& operator<<(ostream& o,const vector<T>& v) {o<<"{";if(SZ(v))o<<join(v,", ");o<<"}";return o;}
template<class T,class U>ostream& operator<<(ostream& o,const pair<T,U>& p) {o<<"(";o<<p.first<<", "<<p.second;o<<")";return o;}

const ll INF = 1e15;
const ll MOD = 1e9+7;
const double EPS = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    string S; cin >> S;
    if (INCLUDE(S, "AC")) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}