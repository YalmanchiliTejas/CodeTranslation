#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int N;
	cin>>N;
	vector<int> a(N);
	vector<ll> b(N+1,0);
	ll mod = 1e9+7;
	for(int i=0;i<N;i++){
		cin>>a[i];
		b[i+1]=b[i]+a[i];
	}
	ll x=0;
	for(int i=0;i<N;i++){
	ll sum =(b[N]-b[i+1])%mod;
	x+=a[i]*sum;
	x%=mod;
	}
    cout<<x<<endl;
    return 0;
}