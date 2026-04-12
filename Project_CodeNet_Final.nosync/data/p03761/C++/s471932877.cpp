#include "bits/stdc++.h"

#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using ull = unsigned long long;
using ll = long long;
constexpr int I_INF = INT_MAX;
constexpr ll L_INF = LLONG_MAX;
const long double PI = (acos(-1));
const ull MOD = 1000000007;


struct __INIT {
    __INIT() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __init;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    vector<map<char,int>> cnt(N);
    for(int i = 0; i < N; i++) for(char c : S[i]) cnt[i][c]++;
    vector<char> ans;
    for(char x = 'a'; x <= 'z'; x++){
        int min_n = I_INF;
        for(int i = 0; i < N; i++) min_n = min(cnt[i][x], min_n);
        for(int i = 0; i < min_n; i++) ans.push_back(x);
    }
    sort(all(ans));
    for(char a : ans) cout << a;
}