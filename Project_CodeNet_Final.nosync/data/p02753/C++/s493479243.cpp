#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream& operator >> (istream& istr, vector<T>& vec){
    for(T& x: vec) istr >> x;
    return istr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<T>& vec){
    if(!vec.empty()){
        ostr << vec.front();
        for(auto itr = ++vec.begin(); itr != vec.end(); itr++)
            ostr << " " << *itr;
    }
    return ostr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<vector<T>>& mat){
    if(!mat.empty()){
        ostr << mat.front();
        for(auto itr = ++mat.begin(); itr != mat.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, pair<T,U>& p){
    ostr << p.first << " " << p.second;
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, vector<pair<T,U>>& mat){
    if(!mat.empty()){
        ostr << mat.front();
        for(auto itr = ++mat.begin(); itr != mat.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
// vll x(n); x[i]=a;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
// vvll x(m,vi(n)); x[i][j]=a;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vpll;
// vpll x(n); x[i]={a,b}; x[i].first/second;

#define PI 3.1415926535897932
#define INF 1e+12
#define EPS 1e-12
#define REP(i,n) for(ll i=0; i<(n); i++)
#define RREP(i,n) for(ll i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORR(i,a,b) for(ll i=(b)-1; i>=(a); i--)
#define dump(x) cout << #x << " = " << (x) << endl
#define all(x) (x).begin(),(x).end()
// sort(all(x));

int main(){
    vc s(3);
    cin >> s;
    if(s[0] != s[1] || s[1] != s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
