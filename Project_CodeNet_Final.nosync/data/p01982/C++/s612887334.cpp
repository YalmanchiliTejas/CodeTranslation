#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define REP(i,n) for(int i = 0;i < n; i++)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e18;

#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
 
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>vector<T>
make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}



signed main(){
	//IOS();
	vector<int>ans;
	while(1){
		int n,l,r;
		cin>>n>>l>>r;
		if(n+l+r==0)break;
		vector<int>a(n);
		REP(i,n)cin>>a[i];
		int cnt = 0;
		rep(i,l,r+1){
			int isuruu = -1;
			rep(j,0,n){
				if(i%a[j])continue;
				if(j%2==0)isuruu = 1;
				else isuruu = 0;
				break;
			}
			if(isuruu==-1){
				if(n%2)isuruu = 0;
				else isuruu = 1;
			}
			if(isuruu)cnt++;
		}
		ans.push_back(cnt);
	}
	for(auto e:ans){
		cout<<e<<endl;
	}
}
