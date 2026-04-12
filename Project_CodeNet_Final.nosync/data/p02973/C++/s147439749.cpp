#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int mod_pow(int x,int y){
	int res=1;
	while(y>0){
		if(y&1)res*=x;
		x*=x;
		res%=mod;x%=mod;
		y>>=1;
	}
	return res;
}
bool prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return x!=1;
}
int n,a[114514];
multiset<int>st;
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n){
		auto it=st.lower_bound(a[i]);
		if(it!=st.begin()){
			it--;
			st.erase(it);
		}
		st.insert(a[i]);
	}
	cout<<st.size()<<endl;
}
