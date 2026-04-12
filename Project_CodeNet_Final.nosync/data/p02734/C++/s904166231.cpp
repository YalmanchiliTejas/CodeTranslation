#include <bits/stdc++.h>
using namespace std;
long long int MOD = 998244353;

int main(){
    int n, s;
    cin >> n >> s;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long int> ans(s+1);
    vector<long long int> exponent(s+1);// formal power series

    for(int i=0; i<n; i++){// * (1 + x^a[i])
        vector<long long int> next(s+1);
        exponent[0] += 1;
        //for(long long int e : exponent) cout << e << " ";
        //cout << endl;

        for(int j=0; j<=s; j++){
            next[j] += exponent[j];
            if(j - a[i] >= 0) next[j] += exponent[j-a[i]];
            next[j] %= MOD;
        }
        exponent = next;
        for(int j=0; j<=s; j++){
            ans[j] += exponent[j];
            ans[j] %= MOD;
        }
    }
    cout << ans[s] << endl;
    return 0;
}