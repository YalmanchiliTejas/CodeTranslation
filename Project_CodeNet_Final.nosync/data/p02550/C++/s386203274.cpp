#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll n,x,m; cin >> n >> x >> m;
	if(n<=200000){
		ll res=x;
		n--;
		ll cur=x*x%m;
		for(int i=0;i<n;i++){
			res+=cur;
			cur=cur*cur%m;
		}
		cout << res << endl;
		return 0;
	}
	ll res=x;
	n--;
	vector<ll> v;
	set<ll> st;
	ll cur=x*x%m;
	while(1){
		if(st.find(cur)!=st.end())break;
		n--;
		res+=cur;
		v.push_back(cur);
		st.insert(cur);
		cur=cur*cur%m;
	}
	bool flag=0;
	ll sum=0;
	ll cnt=0;
	for(ll p:v){
		if(p==cur){
			flag=1;
		}
		if(flag){
			sum+=p;
			cnt++;
		}
	}
	res+=(n/cnt)*sum;
	n%=cnt;
	for(int i=0;i<n;i++){
		res+=cur;
		cur=cur*cur%m;
	}
	// int cnt=0;
	// ll cur=x%m;
	// ll sum=0;
	// while(1){
	// 	if(st.find(cur)!=st.end())break;
	// 	st.insert(cur);
	// 	cnt++;
	// 	sum+=cur;
	// 	cur=cur*cur%m;
	// }
	// n--;
	// ll res=x+(n/cnt)*sum;
	// n%=cnt;
	// for(int i=0;i<n;i++){
	// 	res+=cur;
	// 	cur=cur*cur%m;
	// }
	cout << res << endl;
}