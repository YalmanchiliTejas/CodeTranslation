#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int mod = 7 + pow(10, 9);
    unsigned long long ans = 0;
    
    int sum = 0;
    long long a = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        ans =  (ans + (a * sum) % mod) % mod;
        sum = (sum + a) % mod;
    }
    cout << ans << endl;
}
