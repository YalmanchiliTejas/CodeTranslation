#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

template<typename T>
T mod(T a, T b){
    return (a + b) % b;
}

template<typename T>
T gcd(T a, T b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

// n を素因数分解
map<ll, ll> factor(ll n){
    map<ll, ll> mp;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1) {
        mp[n]++;
    }

    return mp;
}

// 文字列に "hoge" が含まれているか
// string str = "hogepiyo";
// if (str.find("hoge") != string::npos) {
//     cout << "文字列が含まれています" << endl;
// }

// char to string
// char c = 'a';
// string str = {c};

void solve(){
    int N, K;
    string S;
    cin >> N >> S >> K;

    char c = S[K-1];
    for (int i = 0; i < N; i++) {
        if (S[i] != c) {
            S[i] = '*';
        }
    }

    cout << S << endl;

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
