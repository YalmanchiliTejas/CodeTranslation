// https://ynucpc.github.io/blog/2018/04/15/cp_vscode/
// http://www.atmarkit.co.jp/ait/articles/1509/08/news019.html

#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rep3(i,n,m) for(ll i=(n);i<(ll)(m);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b)) 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
int _stoi(string s, int tmp=10){
	istringstream stm(s);
	int res;
	stm >> res;
	return res;
}
double _stod(string s, int tmp=10){
	istringstream stm(s);
	double res;
	stm >> res;
	return res;
}
template<typename T>string to_string(const T& n){
	std::ostringstream stm;
	stm << n;
	return stm.str();
}

// 降順ソート: sort(A, A+N, greater<>());
// min: *min_element(A, A+N)
// argmin: min_element(A, A+N)-A

ll gcd(ll a, ll b){
	if (a==0){
		return b;
	}else{
		return gcd(b%a, a);
	}
}


int main(){	
	// ll A; cin >> A;
	// cout << "hello" << _stoi("14") << max({1,3}) << endl;
	ll N;
	cin >> N;
	ll H[N];
	rep(i, N)cin >> H[i];
	ll ans=0, ma=0;
	rep(i, N){
		if (ma <= H[i]){
			ans++;
			ma = H[i];
		}
	}
	cout << ans << endl;
}






