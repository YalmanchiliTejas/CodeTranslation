#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}

long long count(long long low, long long high, long long div){

    if(low % div == 0 && low > 0)
        return high / div - low / div + 1;

    return high / div - low / div;

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, k;
    cin >> n >> k;

    long long tot = 0;

    for(long long b = k + 1; b <= n; ++b){

        // a % b >= k

        // b - k valid remainders

        long long lowest    = k;
        long long remainder = n % b;
        long long highest   = n - n % b;

        //cout << highest << " " << (b - k) * count(lowest, highest, b) + max(0LL, remainder - k + 1) << endl;

        tot += (b - k) * count(lowest, highest, b) + max(0LL, remainder - (k == 0 ? 1 : k) + 1);

    }

    cout << tot;

    return 0;
}
