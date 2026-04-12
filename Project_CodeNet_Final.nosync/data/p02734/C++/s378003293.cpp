#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define MOD 998244353 
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

ll ans;
int n,s;
int a[3005];
ll dp[3005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++) {
        dp[0]++;
        for(int j=s-a[i]; j>=0; j--)
            dp[j+a[i]]+=dp[j]%MOD;
        ans+=dp[s]%MOD;
    }

    ans%=MOD;
    
    cout << ans << endl;
    return 0;
}

