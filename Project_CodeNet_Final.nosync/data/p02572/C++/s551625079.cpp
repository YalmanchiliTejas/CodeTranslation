#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> v(N);
    long long sum;
    long long mod = pow(10,9)+7;
    for(int i=0;i<N;i++){
        cin >> v[i];
        sum += v[i];
        sum %= mod;
    }
    long long ans=0;
    for(int i=0;i<N-1;i++){
        sum -= v[i];
      //cout << sum << endl;
        if(sum <= 0) sum += mod;
      //cout << sum << endl;
        ans += (v[i] * sum);
        ans %= mod;
      //cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}