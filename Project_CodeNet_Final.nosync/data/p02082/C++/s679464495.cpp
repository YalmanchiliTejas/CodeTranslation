#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n){return (n==0) ? 1 : 10 * TEN(n-1);}
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define rep1(i,N) for(int i=1;i<=(int)(N);i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb eb
#define all(x) x.begin(),x.end()
template<class T, class U> void chmin(T& t, const U& u){ if(t>u) t = u;}
template<class T, class U> void chmax(T& t, const U& u){ if(t<u) t = u;}

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

template<class T,class U>
ostream& operator<<(ostream& os, const pair<T,U>& p){
    return os << "P(" << p.fs << ", " << p.sc << ")";
}
template<class T> ostream& operator<<(ostream& os, const V<T>& v){
    os << "[";
    for(auto d: v) os << d << ", ";
    return os << "]";
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int s,t,p,q,M,y;
    cin >> s >> t >> p >> q >> M >> y;
    cout << (s^t^y) << endl;
}
