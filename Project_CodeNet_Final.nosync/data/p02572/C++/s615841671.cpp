#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    const int MOD = 1000000007;
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        sum += a.at(i);
      	sum %= MOD;
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        sum -= a.at(i);
      	if(sum < 0){
        	sum += MOD;
       	}
        ans += a.at(i)%MOD * sum%MOD;
    }
    cout << ans%MOD << endl;
}
