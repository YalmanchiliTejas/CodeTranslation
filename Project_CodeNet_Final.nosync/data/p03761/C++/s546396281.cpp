#include <bits/stdc++.h>
using namespace std;
//debug
#ifdef grief
#define debug(...) do{\
	fprintf(stderr , "%s - %d : (%s) = " , __PRETTY_FUNCTION__ , __LINE__ , #__VA_ARGS__ );\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){
	cerr<<x<<endl;
}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){
	cerr<<x<<" , ";
	_DO(tail...);
}
#else
#define debug(...)
#endif
//type
typedef long long ll;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef priority_queue<pll,vector<pll>,greater<pll> > heap;
//macro
#define SZ(x) ((ll)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pb push_back
const ll INF=1e9;
const ll MAX=1e6+5;
const ll MOD=1e9+7;
//}}}
int mi[300];
int cnt[300];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i='a';i<='z';i++)
		mi[i]=INF;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(char c:s)
			cnt[c]++;
		for(int i='a';i<='z';i++){
			mi[i]=min(mi[i],cnt[i]);
			cnt[i]=0;
		}
	}
	for(char i='a';i<='z';i++){
		for(int j=0;j<mi[i];j++){
			cout<<i;
		}
	}
	cout<< '\n';
	return 0;
}
