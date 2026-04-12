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
//void solve(){char c;cin>>c;string s="aiueo";if(s.find(c)!=string::npos)cout<<"vowel"<<endl;else cout<<"consonant"<<endl;}
// https://abc050.contest.atcoder.jp/tasks/abc050_a
//void solve(){ll A,B;char op;cin>>A>>op>>B;if(op=='+')cout<<A+B<<endl;else cout<<A-B<<endl;}
// https://abc051.contest.atcoder.jp/tasks/abc051_a
//void solve(){string s;cin>> s;cout<<s.substr(0,5)<<" "<<s.substr(6,7)<<" "<<s.substr(14)<<endl;}
// https://abc052.contest.atcoder.jp/tasks/abc052_a
//void solve(){ll A,B,C,D;cin>>A>>B>>C>>D;cout<<max(A*B,C*D)<<endl;}
// https://abc053.contest.atcoder.jp/tasks/abc053_a
//void solve(){ll x;cin>>x;cout<<(x<1200?"ABC":"ARC")<<endl;}
// https://abc054.contest.atcoder.jp/tasks/abc054_a
//void solve(){ll A,B;cin>>A>>B;if(A==1)A=14;if(B==1)B=14;cout<<(A>B?"Alice":(A==B?"Draw":"Bob"))<<endl;}
// https://abc055.contest.atcoder.jp/tasks/abc055_a
//void solve(){ll N;cin>>N;cout<<800*N-200*(N/15)<<endl;}
// https://abc056.contest.atcoder.jp/tasks/abc056_a
//void solve(){char a,b;cin>>a>>b;if(a=='H')cout<<b<<endl;else if(b=='H')cout<<'D'<<endl;else cout<<'H'<<endl;}
// https://abc057.contest.atcoder.jp/tasks/abc057_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A+B)%24<<endl;}
// https://abc058.contest.atcoder.jp/tasks/abc058_a
//void solve(){ll a,b,c;cin>>a>>b>>c;cout<<(b-a==c-b?"YES":"NO")<<endl;}
// https://abc059.contest.atcoder.jp/tasks/abc059_a
//void solve(){string s1,s2,s3;cin>>s1>>s2>>s3;cout<<(char)toupper(s1[0])<<(char)toupper(s2[0])<<(char)toupper(s3[0])<<endl;}
// https://abc060.contest.atcoder.jp/tasks/abc060_a
//void solve(){string A,B,C;cin>>A>>B>>C;cout<<(A[A.length()-1]==B[0]&&B[B.length()-1]==C[0]?"YES":"NO")<<endl;}
// https://abc061.contest.atcoder.jp/tasks/abc061_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(C>=A&&C<=B?"Yes":"No")<<endl;}
// https://abc062.contest.atcoder.jp/tasks/abc062_a
//void solve(){ll x,y;cin>>x>>y;vector<vector<ll>> g={{1,3,5,7,8,10,12},{4,6,9,11},{2}}; ll gx,gy; for(int i=0;i<3;i++)for(auto v:g[i]){if(v==x) gx=i;if(v==y)gy=i;}cout<<(gx==gy?"Yes":"No")<<endl;}
// https://abc063.contest.atcoder.jp/tasks/abc063_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A+B>=10?"error":to_string(A+B))<<endl;}
// https://abc064.contest.atcoder.jp/tasks/abc064_a
void solve(){ll r,g,b;cin>>r>>g>>b;cout<<((100*r+10*g+b)%4==0?"YES":"NO")<<endl;}


// Main function
int main(void) {cin.tie(0); ios::sync_with_stdio(false); solve(); return 0; }
