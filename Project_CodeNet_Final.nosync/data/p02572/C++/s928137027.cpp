#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll i,j,n,k,sum(0);
	ll val=1e9+7,temp(0),temp2(0);
	cin>>n;
	vector<ll> v(n),s(n+1,0);
	for(i=0;i<n;i++){
		cin>>v[i];
		temp+=v[i];
		s[i+1]=temp;
	}
	for(i=0;i<n-1;i++){
		temp2+=(v[i]*((s[n]-s[i+1])%val))%val;
	}
	cout<<temp2%val;
	







	return 0;
}