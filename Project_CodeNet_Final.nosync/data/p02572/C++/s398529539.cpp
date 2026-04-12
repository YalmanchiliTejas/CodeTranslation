#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7;
ll Mult(ll x,ll y){
	if(x == 0 || y == 0)return 0;
	ll res =0;
	if(y&1)res +=x;
	ll r = Mult(x,y/2)%M;
	res += (r*2)%M;
	return res%M;
}
int main(){
	//freopen("test.in","r",stdin);
	int n;
	cin>>n;
	ll s=0;
	ll res=0;
	ll x;
	for(int i=0;i<n;i++){
		cin>>x;
		res += Mult(x,s)%M;
		res %=M;
		s+=x;
	}
	cout<<res%M<<endl;
    return 0;
}
