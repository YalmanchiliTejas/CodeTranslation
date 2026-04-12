#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define 	pb 				push_back
#define 	MOD 			1000000007
#define 	pp 				pop_back
#define 	MAXN   			1000001
#define 	mp 				make_pair
#define 	endl 			'\n'
#define 	ff 				first
#define 	ss 				second
#define 	mapcl 			map<char,ll>
#define 	mapll 			map<ll,ll>
#define 	pll 			pair<ll,ll>
#define 	cmp 			complex<double>
#define 	pi 				3.141592653589793238462643383279502884197169399375105820974944592307816406286 
#define 	inf 			1000
#define 	vll 			vector<ll>
#define 	all(v) 			v.begin(),v.end()
#define 	fr(i,z,n) 		for(ll i=z;i<n;i++)
#define 	sqrt 			sqrtl
#define 	cbrt 			cbrtl
#define		ll 				long long
#define 	ld 				long double
bool 		coll(pll p1,pll p2,pll p3)		{if((p3.ss-p2.ss)*(p2.ff-p1.ff)==(p2.ss-p1.ss)*(p3.ff-p2.ff))return true;else return false;}
void		print(auto x)					{cout<<x<<endl;}
void 		pv(vector<auto> v)				{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void 		pvsl(vector<auto> v)			{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";}
void 		in(vector<auto> &v, ll n)		{v.resize(n);for(ll i=0;i<n;i++)cin>>v[i];}
void 		sortv(vector<auto> &v)			{sort(v.begin(),v.end());}
void 		fast()							{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
ll maxi(ll a, ll b){ 
	if (a > b)
		return a;
	return b;
}
ll mini(ll a, ll b){
	if (a > b)
		return b;
	return a;
}
string increment(string s){
	ll size = (ll)s.size();
	bool flag = true;
	//aaa
	for (ll i=size-1;i>=0;i--){
		s[i] += 1;
		if (s[i] > 'z'){
			s[i] = 'a';
		}
		else{
			flag = false;
			break;
		}
	}
	if (flag){
		s = 'a' + s;
	}
	return s;
}
int main(){
	ll n, m;
	cin >> n >> m;
	if (n == m){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
