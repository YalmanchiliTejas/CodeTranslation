#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	long long int a;
	cin >> t;
	int d = t;
	long long int sum = 0;
	long long int sum2 = 0;
	long long int mod = 1000000007;
	vector<long long int> v;
	while(t--){
		cin>>a;
		v.push_back(a);
		sum+=a;
	}
	for(int i=0;i<d;i++){
		sum-=v[i];
		sum2 += (sum%mod*v[i]%mod)%mod;
	}
	sum2%=mod;
	cout << sum2 << endl;
		
	return 0;
}

