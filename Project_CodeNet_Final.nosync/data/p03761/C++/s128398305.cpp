#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}

int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for(ll i = 0;i < n;i++){
        cin >> s[i];
    }

    vector<ll> ans(26);
    for(ll i = 0;i < n;i++){
        vector<ll> t(26);
        for(ll j = 0;j < s[i].size();j++){
            t[(int)(s[i][j] - 'a')]++;
        }
        for(ll j = 0;j < 26;j++){
            if(ans[j] > t[j] || i == 0){
                ans[j] = t[j];
            }
            //cout << t[j];
        }
        //cout << endl;
    }

    for(ll i = 0;i < 26;i++){
        //cout << ans[i] << endl;
        while(ans[i] != 0){
            cout << (char)(i + 'a');
            ans[i]--;
        }
    }

    return 0;
}