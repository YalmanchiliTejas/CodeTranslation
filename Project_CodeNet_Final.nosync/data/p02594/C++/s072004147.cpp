#include<bits/stdc++.h>
#define lint long long int
#define rep(i,n) for(int i=0;i<int(n);i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define fill(a,x) fill(a.begin(),a.end(),x)
#define eb(data) emplace_back(data)
#define pb(data) emplace_back(data)
#define mp make_pair
#define ALNUM 26
#define vint vector<int>
#define vlint vector<lint>
#define F first
#define S second
#define ALL(data) data.begin(),data.end()
#define GEts(s) getline(cin,s);
#define UNIQUE(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())

using namespace std;
template<typename Rast>inline void out(Rast rast){cout<<rast<<"\n";return;}
template<typename Rast>inline void in(Rast& rast){cin>>rast;return;}
template<typename T>istream& operator >> (istream& is, vector<T>& vec){for(T& x: vec) is >> x;return is;}
template<typename First, typename... Rest>void in(First& first, Rest&... rest){cin >> first;in(rest...);return;}
template<typename First, typename... Rest>void out(First first, Rest... rest){cout << first<<" ";out(rest...);return;}
template<typename T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<typename T1,typename T2>bool chmax(T1& a,T2 b){if(a<b){a=b;return true;}else{return false;}}
template<typename T1,typename T2>bool chmin(T1& a,T2 b){if(a>b){a=b;return true;}else{return false;}}
template<typename T>T lcm(T a, T b){return a * b / gcd(a, b);}
static const double pi = 3.141592653589793;
int modpow(int a,int n,int p){if (n==0)return 1%p; if(n==1)return a%p;if(n%2==1)return (a*modpow(a,n-1,p))%p;lint t=modpow(a,n/2,p);return (t*t)%p;}//a^n%p
lint MOD=pow(10,9)+7;
//lint MOD=998244353;
lint inf=pow(2,50);
int intinf=pow(2,30);
/**int dirx[]={1,0};int diry[]={0,1};//*///右、下
/**int dirx[]={0,1,0,-1};int diry[]={-1,0,1,0};//*///四方位
/**int dirx[]={-1,0,1,1,1,0,-1,-1};int diry[]={-1,-1,-1,0,1,1,1,0};//*///八方位


class unionfind{
public:
	vector<int> table;
	void init(int size){
		table.resize(size);
		rep(i,size)table[i]=i;
	};
	int root(int index){
		if(table[index]==index)return index;
		else{
			int hoge=root(table[index]);
			table[index]=hoge;
			return hoge;
		}
	};
	bool same(int x,int y){
		return(root(x)==root(y));
	};
	int marge(int x,int y){
		int yroot=root(y);
		int xroot=root(x);
		if(xroot==yroot)return 0;
		table[yroot]=xroot;
		return 0;
	}
};



int main(){
	cin.tie(0);ios::sync_with_stdio(false);cout<<std::fixed<<std::setprecision(19);
	int xl;
	in(xl);
	if(xl<30)out("No");
	else out("Yes");
	return 0;
}
