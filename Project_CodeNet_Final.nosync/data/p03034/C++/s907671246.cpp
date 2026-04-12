#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
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

void pv(vector<int>&v){
	for(int i = 0;i<v.size();i++){
		if(i)cout<<' ';
		cout<<v[i];
	}
	cout<<endl;
}



signed main(){
	IOS();
	int N;
	cin >> N;
	vector<int>s(N);
	for(int i = 0;i < N;i++){
		cin>>s[i];
	}
	int ans = 0;
	rep(i,1,N/2){
		int l = 0,r = N - 1;
		int cost = 0;
		map<int,int>visit;
		while(0<=r&&l<N&&visit.count(l)==0&&visit.count(r)==0){
			if(l+i>=N-1)break;
			visit[l] = true;
			visit[r] = true;
			cost += s[l] + s[r];
			l += i;
			r -= i;
			chmax(ans,cost);
			if(l==r)break;
		}
	}
	cout<<ans<<endl;
}
