#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll kaij(ll n) {
    if(n <= 1) {
        return 1;
    }
    return n*kaij(n - 1);
}
ll C(ll n, ll k) {
    //cout << "##" << endl;
    //cout << kaij(n) << endl;
    //cout << kaij(k) << endl;
    //cout << kaij(n - k) << endl;
    //return kaij(n)/(kaij(k)*kaij(n - k));
    int ans = 1;
    for(int i = 0; i < k; i++) {
        ans *= n - i;
        ans /= i + 1;
    }

    return ans;
}

//n桁のうちk個の数字が0でないとき
ll solve(ll n,ll k) {
    ////cout << "##" << endl;
    //cout << ':' << pow(9,k) << endl;
    //cout << '=' << C(n, k) << endl;
    return (ll)pow(9,k)*C(n, k);
}

int main() {
    string N;
    ll K;
    cin >> N >> K;
    ll n = N.size();
    string memoN = N;
    //cout << "##" << endl;
    //cout << kaij(5) << endl;
    //cout << N.at(0) - '0' << endl;
    //cout << solve(n - 1, K) << endl;
    ll ans;
    if(n < K) {
        cout << 0 << endl;
        return 0;
    }
    if(n > K) {
        ans = solve(n - 1, K);
    } else if(n == 1 && K == 1) {
        cout << N << endl;
        return 0;
    } else if(n == 2 && K == 2) {
        cout << stoi(N) - stoi(N)/10 - 9 << endl;
        return 0;
    } else if(n == 3 && K == 3) {
        int intN = stoi(N);
        cout << intN - intN/10 - 99 << endl;
        return 0;
    }
    //cout << ans << endl;
    //cout << "##" << endl;
    for(int i = 1; i < n; i++) {
        memoN.at(i) = '0';
    }
    //cout << "##" << endl;
    if(K == 3) {
        ans += (N.at(0) - '1')*solve(n - 1, K - 1);
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = 0; k < 9; k++) {
                    for(int l = 0; l < 9; l++) {
                        string checkN = memoN;
                        checkN.at(i) = '1' + k;
                        checkN.at(j) = '1' + l;
                        if(checkN <= N) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    if(K == 2) {
        ans += (N.at(0) - '1')*solve(n - 1, K - 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 9; j++) {
                string checkN = memoN;
                checkN.at(i) = '1' + j;
                if(checkN <= N) {
                    ans++;
                }
            }
        }
    }
    if(K == 1) {
        ans += N.at(0) - '0';
    }

    cout << ans << endl;

    
    

    return 0;
}