#include "bits/stdc++.h"

#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using ull = unsigned long long;
using ll = long long;

struct __INIT {
    __INIT() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __init;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<map<char, int>> count(N, map<char,int>());
    for (int i = 0; i < N; i++) {
        for (char s : S[i]) {
            count[i][s]++;
        }
    }
    string short_s;
    for (char s = 'a'; s <= 'z'; s++) {
        int min_s = 10;
        for (int i = 0; i < N; i++) {
                    min_s = min(count[i][s], min_s);
        }
        for( int i = 0; i < min_s; i++){
            short_s += s;
        }
    }
    sort(all(short_s));
    cout << short_s << endl;
}