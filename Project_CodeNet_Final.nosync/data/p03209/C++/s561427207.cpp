#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
typedef long long ll;
 vector<ll> v, p;
ll dfs(ll n,ll x){
    if(n==0){
        return x <= 0 ? 0 : 1;
    }
    else if(x<=1+v[n-1])
        return dfs(n - 1, x - 1);
    else
        return p[n - 1] + 1+dfs(n - 1, x - 2 - v[n - 1]);
}

int main(){
    ll N, X;
    cin >> N>>X;

    v.assign(N+1, 1);
    p.assign(N + 1, 1);
    for (int i = 0; i < N; i++)
    {
        v[i+1]=(2 * v[i] + 3);
        p[i+1]=(2 * p[i] + 1);
    }

    cout << dfs(N, X) << endl;

    return 0;
}