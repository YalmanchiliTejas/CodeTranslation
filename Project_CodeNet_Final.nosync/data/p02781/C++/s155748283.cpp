#include <bits/stdc++.h> 
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define maxnkp make_pair
#define fi first
#define se second
#define eps 1e-6
using namespace std;
typedef long long ll;
const int mods = 1e9+7;
const int maxn = 2e5+10;
const int N = 1e5+10;
const int E = 1e6+10; 
string s;
ll n,k;
ll ans;

ll solve_1(ll del){
	ll res = 0;
	while(s[0+del]=='0'&&del<n) del++;
	if(del>=n) return 0;
	res+=(ll)(s[0+del]-'0')+9*(n-1-del);
	return res;
}

ll solve_2(ll del){
	ll res = 0;
	while(s[0+del]=='0'&&del<n) del++;
	if(del>=n) return 0;
	for(ll i=0+del;i<n;i++){
		if(i==0+del){
			res+=solve_1(del+1)+(ll)(s[0+del]-'0'-1)*9*(n-1-del);
		}
		else{
			res+=9*9*(n-i-1);
		}
	}
	return res;
}

ll solve_3(ll del){
	ll res = 0;
	for(ll i = 0+del;i<n;i++){
		if(i==0+del){
			res+=solve_2(del+1)+(ll)(s[0]-'0'-1)*(((n-1)*(n-2))/2)*81;
		}
		else{
			res+=9*(((n-i-1)*(n-i-2))/2)*81;
		}
	}
	return res;
}

int main(){
	cin>>s>>k;
	n = s.size();
	if(n<k){
		printf("0\n");
		return 0;
	}
	if(k==1) ans = solve_1(0);
	if(k==2) ans = solve_2(0);
	if(k==3) ans = solve_3(0);
	cout<<ans<<endl; 
}
