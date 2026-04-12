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
#define SHOW(x)     cout<<#x<<" = "<<x<<endl
#define SORT(v)     sort(ALL(v))
#define SZ(v)       (ll)(v).size()
#define UNIQ(v)     SORT(v);(v).erase(unique(ALL(v)),(v).end())
#define PERM(c)     for(bool p=1;p;p=next_permutation(ALL(c)))
#define PQ(T)       priority_queue<T,vector<T>,greater<T>>

template<typename T>string join(const vector<T>& v, string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(d.length());}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v)
{if(SZ(v))s<<join(v,", ");return s;}

const ll inf = 1e15;
const ll mod = 1e9+7;
const double eps = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ll N; cin >> N;
    vector<ll> X(N), Y(N); REP(i, N) cin >> X[i], Y[i] = X[i];
    
    SORT(Y);
    ll m1 = Y[N / 2 - 1];
    ll m2 = Y[N / 2];
    
    REP(i, N) {
        if (X[i] <= m1) cout << m2 << endl; 
        else cout << m1 << endl;
    }
    
    return 0;
}
