#include <bits/stdc++.h>
int main()
{
    int N;
    std::cin >> N;
    using ll = long long;
    std::vector<ll> s(N);
    for(int i = 0; i < N; i++){std::cin >> s[i];}
    ll ans = 0LL;
    for(ll c = 1; c < N; c++){
        ll sum = 0;
        for(ll k = 0; c*k < (ll)N-1LL; k++){
            const ll A = N-1-c*k;
            if(A <=c){break;}
            if(2LL*c*k == N-1 or 2LL*c*k == N-1+c){break;}
            sum += s[c*k] + s[N-1-c*k];
            ans = std::max(ans, sum);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
