// C - 怪文書 / Dubious Document
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define MOD 1000000007
#define rp(i,n) for(int i=0;i<(n);i++)
#define irp(i,n) for(int i=(n);i>=0;i--)
#define up(i,s,e,d) for(int i=(s);i<(e);i+=(d))
#define dw(i,s,e,d) for(int i=(s);i>(e);i-=(d))
// #define in(x) cin>>(x)
#define ot(x) cout<<(x)
#define ote(x) cout<<(x)<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define vecmax(v) (*max_element(v.begin(),v.end()))
#define range(v,x) (iota((v).begin(),(v).end(),(x)))
void bye(auto x, int code=0){cout<<(x)<<endl;exit(code);}
// int in(){int x;cin>>x;return x;}
int in(){int x;scanf("%d",&x);return x;}
// template<class T> T in(){T x;cin>>x;return x;}

void vprn(vector<int> &v){ for(int i=0;i<v.size();i++) cout<<v[i]<<(i<v.size()-1?",\t":"\n"); }
void vvprn(vector<vector<int>> &vv){ for(auto v:vv) vprn(v); }

// template<class T> void vprn(T &v, string s, string m, string e)
// {cout<<s;for(int i=0;i<v.size();i++)cout<<v[i]<<m;cout<<e;}
// template<class T> void vvprn(T &vv, string s, string m, string e)
// {for(auto v:vv) vprn(v,s,m,e);}

#define otreal(n,p) cout<<fixed<<setprecision(p)<<(n)

int main(){
	int n; cin>>n;
	// vector<string> S(n);
	vvi S(n,vi(26));
	// map<int,int> m;
	// ote('z'-'a');
	up(i,0,n,1){
	// 	// cin>>S[i];
		string s; cin>>s;
		// ote(s);
		for(auto e:s){
			// ote(e);
			S[i][e-'a']++;
		}
	}

	// vvprn(S);

	string ans;
	rp(i,26){
		int mini = 1e9;
		rp(j,n){
			if(mini>S[j][i]){
				mini = S[j][i];
			}
		}
		rp(k,mini){
			ans += i+'a';
		}
	}

	ote(ans);
}