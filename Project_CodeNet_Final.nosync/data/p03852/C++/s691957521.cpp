#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}
/*
 Atcoder 100~200点代
 アな問題が多いので,まとめる
*/
// https://abc042.contest.atcoder.jp/tasks/abc042_a
//void solve(){ ll A,B,C; cin >> A >> B >> C; if(A == 5 && B == 5 && C == 7){ cout << "YES" << endl; return;} if(A == 5 && B == 7 && C == 5){ cout << "YES" << endl; return;} if(A == 7 && B == 5 && C == 5){ cout << "YES" << endl; return;} cout << "NO" << endl; return ; }
// https://abc043.contest.atcoder.jp/tasks/abc043_a
//void solve(){ ll N; cin >> N; cout << N*(N+1)/2 << endl; }
// https://abc044.contest.atcoder.jp/tasks/abc044_a
//void solve(){ll N,K,X,Y;cin>>N>>K>>X>>Y; cout<<X*min(N,K)+Y*max(0LL,N-K)<<endl;}
// https://abc045.contest.atcoder.jp/tasks/abc045_a
//void solve(){ll a,b,h;cin>>a>>b>>h;cout<<(a+b)*h/2<<endl;}
// https://abc046.contest.atcoder.jp/tasks/abc046_a
//void solve(){ ll a,b,c; cin >> a >> b >> c; set<ll> s; s.insert(a); s.insert(b); s.insert(c); cout << s.size() << endl; }
// https://abc047.contest.atcoder.jp/tasks/abc047_a
//void solve(){ll a,b,c;cin>>a>>b>>c;if(a==b+c||b==a+c||c==a+b)cout<<"Yes"<<endl;else cout<<"No"<<endl;}
// https://abc048.contest.atcoder.jp/tasks/abc048_a
//void solve(){string s1,s2,s3;cin>>s1>>s2>>s3;cout<<"A"<<s2[0]<<"C"<<endl;}
// https://abc049.contest.atcoder.jp/tasks/abc049_a
void solve(){char c;cin>>c;string s="aiueo";if(s.find(c)!=string::npos)cout<<"vowel"<<endl;else cout<<"consonant"<<endl;}
// https://abc050.contest.atcoder.jp/tasks/abc050_a
//void solve(){}
// https://abc051.contest.atcoder.jp/tasks/abc051_a
//void solve(){}
// https://abc052.contest.atcoder.jp/tasks/abc052_a
//void solve(){}
// https://abc053.contest.atcoder.jp/tasks/abc053_a
//void solve(){}
// https://abc054.contest.atcoder.jp/tasks/abc054_a
//void solve(){}

// Main function
int main(void) {cin.tie(0); ios::sync_with_stdio(false); solve(); return 0; }
