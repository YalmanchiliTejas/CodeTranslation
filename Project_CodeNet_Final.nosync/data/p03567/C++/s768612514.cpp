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
//void solve(){ll r,g,b;cin>>r>>g>>b;cout<<((100*r+10*g+b)%4==0?"YES":"NO")<<endl;}
// https://abc065.contest.atcoder.jp/tasks/abc065_a
//void solve(){ll X,A,B;cin>>X>>A>>B;cout<<(A>=B?"delicious":(X+A>=B?"safe":"dangerous"))<<endl;}
// https://abc066.contest.atcoder.jp/tasks/abc066_a
//void solve(){ll a,b,c;cin>>a>>b>>c;cout<<min({a+b,b+c,c+a})<<endl;}
// https://abc067.contest.atcoder.jp/tasks/abc067_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A%3==0||B%3==0||(A+B)%3==0?"Possible":"Impossible")<<endl;}
// https://abc068.contest.atcoder.jp/tasks/abc068_a
//void solve(){ll N;cin>>N;cout<<"ABC"<<N<<endl;}
// https://abc069.contest.atcoder.jp/tasks/abc069_a
//void solve(){ll n,m;cin>>n>>m;cout<<(n-1)*(m-1)<<endl;}
// https://abc070.contest.atcoder.jp/tasks/abc070_a
//void solve(){ll N;cin>>N;cout<<(to_string(N)[0]==to_string(N)[2]?"Yes":"No")<<endl;}
// https://abc071.contest.atcoder.jp/tasks/abc071_a
//void solve(){ll x,a,b;cin>>x>>a>>b;cout<<(abs(x-a)<abs(x-b)?"A":"B")<<endl;}
// https://abc072.contest.atcoder.jp/tasks/abc072_a
//void solve(){ll X,t;cin>>X>>t;cout<<max(0LL,X-t)<<endl;}
// https://abc073.contest.atcoder.jp/tasks/abc073_a
//void solve(){ll N;cin>>N;cout<<(to_string(N).find('9')!=string::npos?"Yes":"No")<<endl;}
// https://abc074.contest.atcoder.jp/tasks/abc074_a
//void solve(){ll N,A;cin>>N>>A;cout<<N*N-A<<endl;}
// https://abc075.contest.atcoder.jp/tasks/abc075_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(A==B?C:(B==C)?A:B)<<endl;}
// https://abc076.contest.atcoder.jp/tasks/abc076_a
//void solve(){ll R,G;cin>>R>>G;cout<<2*G-R<<endl;}
// https://abc077.contest.atcoder.jp/tasks/abc077_a
//void solve(){char C[2][3];for(int i=0;i<2;i++)for(int j=0;j<3;j++)cin>>C[i][j];for(int i=0;i<3;i++)if(C[0][i]!=C[1][2-i]){cout<<"NO"<<endl;return;}cout<<"YES"<<endl;}
// https://abc078.contest.atcoder.jp/tasks/abc078_a
//void solve(){string A,B;cin>>A>>B;ll a=stoi(A,nullptr,16),b=stoi(B,nullptr,16); cout<<(a>b?">":(a==b?"=":"<"))<<endl;}
// https://abc079.contest.atcoder.jp/tasks/abc079_a
//void solve(){ll N;cin>>N;string S=to_string(N);cout<<((S[0]==S[1]&&S[1]==S[2]&&S[2]==S[0])||(S[1]==S[2]&&S[2]==S[3]&&S[3]==S[1])?"Yes":"No")<<endl;}
// https://abc080.contest.atcoder.jp/tasks/abc080_a
//void solve(){ll N,A,B;cin>>N>>A>>B;cout<<min(A*N,B)<<endl;}
// https://abc081.contest.atcoder.jp/tasks/abc081_a
//void solve(){string s;cin>>s;int ans=0;for(auto c:s)if(c=='1')ans++;cout<<ans<<endl;}
// https://abc082.contest.atcoder.jp/tasks/abc082_a
//void solve(){ll a,b;cin>>a>>b;cout<<int((double)(a+b)/2.0 + 0.5)<<endl;}
// https://abc083.contest.atcoder.jp/tasks/abc083_a
//void solve(){ll A,B,C,D;cin>>A>>B>>C>>D;ll L=A+B,R=C+D;cout<<(L>R?"Left":(L==R)?"Balanced":"Right")<<endl;}
// https://abc084.contest.atcoder.jp/tasks/abc084_a
//void solve(){ll M;cin>>M;cout<<48-M<<endl;}
// https://abc085.contest.atcoder.jp/tasks/abc085_a
//void solve(){string S;cin>>S;S[3]='8';cout<<S<<endl;}
// https://abc086.contest.atcoder.jp/tasks/abc086_a
//void solve(){ll a,b;cin>>a>>b;cout<<(a*b&1?"Odd":"Even")<<endl;}
// https://abc087.contest.atcoder.jp/tasks/abc087_a
//void solve(){ll X,A,B;cin>>X>>A>>B;cout<<(X-A)-(X-A)/B*B<<endl;}
// https://abc088.contest.atcoder.jp/tasks/abc088_a
//void solve(){ll N,A;cin>>N>>A;cout<<(N%500<=A?"Yes":"No")<<endl;}
// https://abc089.contest.atcoder.jp/tasks/abc089_a
//void solve(){ll N;cin>>N;cout<<N/3<<endl;}
// https://abc090.contest.atcoder.jp/tasks/abc090_a
//void solve(){char c[3][3];for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)cin>>c[i][j];cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;}
// https://abc091.contest.atcoder.jp/tasks/abc091_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(A+B>=C?"Yes":"No")<<endl;}
// https://apc001.contest.atcoder.jp/tasks/apc001_a
//void solve(){ll X,Y;cin>>X>>Y;cout<<(X%Y==0?-1:X*(Y-1))<<endl;}
// https://cf16-final-open.contest.atcoder.jp/tasks/codefestival_2016_final_a
//void solve(){ll H,W;cin>>H>>W;string S;for(int i = 0; i < H;i++)for(int j = 0; j < W;j++){cin>>S;if(S=="snuke")cout<<(char)('A'+j)<<i+1<<endl;}}
// https://code-festival-2016-quala.contest.atcoder.jp/tasks/codefestival_2016_qualA_a
//void solve(){string s;cin>>s;cout<<s.substr(0,4)<<" "<<s.substr(4)<<endl;}
// https://code-festival-2016-qualb.contest.atcoder.jp/tasks/codefestival_2016_qualB_a
//void solve(){string S;cin>>S;string s="CODEFESTIVAL2016";int ans = 0;for(int i=0;i<16;i++)if(S[i]!=s[i])ans++;cout<<ans<<endl;}
// https://code-festival-2016-qualc.contest.atcoder.jp/tasks/codefestival_2016_qualC_a
//void solve(){string s;cin>>s;bool f=false;for(int i = 0; i < s.length();i++) if(!f){if(s[i]=='C')f=true;}else{if(s[i]=='F'){cout<<"Yes"<<endl;return;}}cout<<"No"<<endl;}
// https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_a
//void solve(){string S;cin>>S;cout<<(S.substr(0,4)=="YAKI"?"Yes":"No")<<endl;}
// https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_a
//void solve(){string S;cin>>S;cout<<S.substr(0,S.length()-8)<<endl;}
// https://code-festival-2017-qualc.contest.atcoder.jp/tasks/code_festival_2017_qualc_a
void solve(){string S;cin>>S;for(int i = 0;i<S.length()-1;i++)if(S[i]=='A'&&S[i+1]=='C'){cout<< "Yes"<<endl; return;}cout<<"No"<<endl;}


// Main function
int main(void) {cin.tie(0); ios::sync_with_stdio(false); solve(); return 0; }
