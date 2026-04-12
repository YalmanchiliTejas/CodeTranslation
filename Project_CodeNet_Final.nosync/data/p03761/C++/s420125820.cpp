#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define gridif(a,x,b) if((a)<=(x)&&(x)<(b))

using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
const int mod=1000000007;

int digitsum(int n,int b){
	if(b<2) return -1;
	if(n<b) return n;
	return digitsum(n/b,b)+n%b;
}
int mpow(int a,int x);
int m_inv(int n);
vector<int> split(int n,int a);
string xal_number(int n,int x);
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
class Factorial{
private:
	vector<int> fac;
public:
	Factorial(int N){
		fac.push_back(1);
		rep(i,N) fac.push_back(fac[i]*(i+1)%mod);
	}
	int fact(int a){return fac[a];}
	int ifac(int a){return m_inv(fac[a]);}
	int cmb(int n,int r);
};
struct UnionFind {
    vector<int> par; // 親ノード
    UnionFind(int n = 1) { init(n);}
    void init(int n = 1) {
        par.resize(n);
        rep(i,n) par[i] = -1;
    }
    int root(int x) {
        if (par[x] <0) return x;
        else return par[x] = root(par[x]);      
    }
    int size(int x){ return -par[root(x)];}
    bool issame(int x, int y) {return root(x)==root(y);}
    bool connect(int x, int y);
};

signed main(){
	map<char,int> pre;
	int n;
	cin>>n;
	rep(i,n){
		map<char,int> now;
		string s;
		cin>>s;
		if(i==0){rep(j,s.size()) now[s[j]]++;}
		else{
			rep(j,s.size()){
				if(pre[s[j]]>now[s[j]]) now[s[j]]++;
			}
		}
		pre=now;
	}
	string ans;
	itr(i,pre){
		rep(j,i->second) ans.push_back(i->first);
	}
	sort(All(ans));
	cout<<ans<<endl;
}