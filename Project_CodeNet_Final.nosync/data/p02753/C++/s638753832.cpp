#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}


int main() {
    long long a = 0, b = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'A'){
            a++;
        }
        if (s[i] == 'B'){
            b++;
        }
    }
    if (a > 0 && b > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}