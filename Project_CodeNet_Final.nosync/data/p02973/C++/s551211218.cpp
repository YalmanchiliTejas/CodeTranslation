#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % MOD;
       base = base * base % MOD;
    }
    return tot;
}

int arr[12], bon[12];
long long dp[12][1001];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a; cin >> n;

    // greedy, add to pile with highest number that is smaller?

    multiset<int> stacks;

    for(int i = 0; i < n; ++i){
        cin >> a;
        auto it = stacks.lower_bound(a);
        if(it != stacks.begin()){
            --it;
            stacks.erase(it);
        }
        stacks.insert(a);
    }

    cout << stacks.size() << "\n";

    return 0;

}
