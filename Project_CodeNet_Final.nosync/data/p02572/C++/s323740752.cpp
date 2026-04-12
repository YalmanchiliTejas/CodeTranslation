#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)


int main(){
    int n; cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    long long x = 1000000000 + 7;
    vector<long long> partial;

    rep(i, n){
        cin >> a.at(i);
        // a.at(i) = a.at(i);
    }

    int partial_s = 0;
    for(int i = 0; i < n; i++){
        partial_s += a.at(n - 1 - i);
        partial_s = partial_s % x;
        partial.push_back(partial_s);
    }

    reverse(partial.begin(), partial.end());

    // rep(i, n){
    //     cout << partial.at(i) << endl;
    // }
    

    for(int i = 0; i < n - 1; i++){
        ans += a.at(i) * partial.at(i+1) % x;
        ans = ans % x;
        // cout << a.at(i) << " " << partial.at(i+1) << endl;
    }

    cout << ans << endl;




    
}