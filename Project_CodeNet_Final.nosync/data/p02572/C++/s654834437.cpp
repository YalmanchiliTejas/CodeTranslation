#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, mod;
    cin >> N;
    vector<int> vec(N);
    mod = 1000000007;
    int64_t sum = 0;
    long ans = 0;
    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
        sum += vec.at(i);
        sum %= mod;
    }
    for (int i = 0; i < N; i++){
        sum -= vec.at(i);
        if (sum < 0) sum += mod;
        ans += sum * vec.at(i);
        ans %= mod;
    }
    cout << ans <<endl;
}