#include <bits/stdc++.h>

#define watch(x) cout<<#x<<" -> "<<x<<endl
#define ALL(x) x.begin() , x.end()
#define INF 100000
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        long long  n;
        cin>>n;
        long long mod = 1e9 + 7;
        long long sum = 0;
        vector<long long> arr(n + 1) , pref(n + 1);
        for (int i = 1;i<=n ;i++){
            cin>>arr[i];
        }
        pref[n] = arr[n];
        for (int i = n-1;i >=1;i--){
            pref[i] = (pref[i + 1] + arr[i])%mod;
        }
        for (int i = 1;i<n ;i ++){
            sum = (sum + (arr[i] * pref[i + 1]) % mod) % mod;
        }
        cout<<sum<<endl;
}