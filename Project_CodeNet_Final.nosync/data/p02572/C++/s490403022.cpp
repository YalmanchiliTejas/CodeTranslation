#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;

long long mult(long long first,long long second){
    return (((first%mod)*(second%mod))%mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long>a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    long long ans = 0;
    vector<long long>second(n);
    second[n-1] = a[n-1];
    for(int i = n-1; i >= 2; --i){
        second[i-1] = a[i-1]+second[i];
    }
    second[n-1] = a[n-1];
//    second[]
//   for(long long s : second){
//        cout << s << " ";
//    }
    for(int i = 1; i < n; ++i){
        ans = (ans%mod + mult(a[i-1],second[i])%mod)%mod;
    }
//    ans = (ans%mod + )
//cout << "ANS? " << ans << endl;
//    cout << endl;
//    ans = 0;
//    for(int i = 0; i < n; ++i){
//        for(int j = i + 1; j < n; ++j){
//            ans = (ans%mod + mult(a[i],a[j])%mod)%mod;
//        }
//    }
    cout << ans << endl;


    return 0;
}
