#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int n;
vector<int> a;
vector<vector<ll>> dp;
vector<vector<int>> flag;

ll rec(int s,int e){
    if(flag.at(s).at(e)) return dp.at(s).at(e);
    if(s == e) return a.at(s);
    flag.at(s).at(e) = 1;
    return dp.at(s).at(e) = max(a.at(s) - rec(s+1,e) , a.at(e) - rec(s,e-1));
}

int main(){

    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a.at(i);
    dp.resize(n,vector<ll>(n));
    flag.resize(n,vector<int>(n,0));

    cout << rec(0,n-1) << endl;
    return 0;   

}
