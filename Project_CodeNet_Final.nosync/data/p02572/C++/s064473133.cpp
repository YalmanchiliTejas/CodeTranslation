#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> b(n+1, 0);
    long long sum;
    long ans=0;
	int mod = 1000000007;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i + 1] = b[i] + a[i];
	}
	
	for (int i = 0; i < n; i++){
	    sum = (b[n]-b[i+1]) % mod;
	    ans += a[i]*sum;
	    ans %= mod;
	}
	
    cout << ans << endl;
    return 0;
}