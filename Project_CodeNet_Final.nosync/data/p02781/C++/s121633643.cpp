#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb(int n, int k)
{
    ll ans = 1;
    for(int i=0; i<k; i++) ans *= (n-i);
    for(int i=1; i<=k; i++) ans /= i;
    return ans;
}

int my_pow(int num, int k)
{
    if(k<=0) return 0;
    int ans = 1;
    for(int i=0; i<k; i++) ans *= num;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int K;
    cin >> K;

    int N = S.length();
    ll ans = 0;
    for(int i=0; i<N; i++)
    {
        int num = S[i] - '0';
        if(num==0) continue;
        K--;
        // i: 1~num-1
        ans += (num-1) * my_pow(9, K) * comb(N-i-1, K);
        // i: 0
        ans += my_pow(9, K+1) * comb(N-i-1, K+1);
        if(K==0)
        {
            ans += num;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
