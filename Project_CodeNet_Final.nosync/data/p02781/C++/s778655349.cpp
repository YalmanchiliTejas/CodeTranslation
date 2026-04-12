#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	debug("debug test\n");
   	string s;
	int k;cin>>s>>k;
	int l = s.length();
	int u = s[0]-'0';
	int wa = 0;
			for(int i = 1;i < l;i++){
				wa += s[i]-'0';
			}
	if(k==1){
		cout << (l-1)*9+(s[0]-'0') << endl;
	}else if(k==2){
		if(l <= 1){
			cout << 0 << endl;
		}else{
			int memo2 = 81*(l-1)*(l-2)/2 + (u-1)*(l-1)*9;
			s.erase(0, 1);
			rep(i, l-1){
				if(s[0]=='0'){s.erase(0, 1);}else{break;}
			}
			l = s.length();
			if(l == 0) cout << memo2 << endl;
			else cout << memo2 + (l-1)*9+(s[0]-'0') << endl; 
		}
	}else{
		if(l <= 2){
			cout << 0 << endl;
		}else{
			ll memo3 = 9*9*9*(l-1)*(l-2)*(l-3)/6 + (u-1)*(l-1)*(l-2)/2*9*9;
			s.erase(0, 1);
			rep(i, l-1){
				if(s[0]=='0'){s.erase(0, 1);}else{break;}
			}
			l = s.length();
			if(l <= 1){
				cout << memo3 << endl;
				return 0;
			}
			u = s[0] - '0';
			ll memo2 = 81*(l-1)*(l-2)/2 + (u-1)*(l-1)*9;// + (l-2)*9+(s[1]-'0');
			s.erase(0, 1);
			rep(i, l-1){
				if(s[0]=='0'){s.erase(0, 1);}else{break;}
			}
			l = s.length();
			if(l == 0){
				cout << memo3 + memo2 << endl;
				return 0;
			}
			cout << memo2 + memo3 + (l-1)*9+(s[0]-'0')<< endl;
		}
	}
	
	return 0;
}
