#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

ll choose(ll n, ll k) //k<=3
{
    if (k==0) return 1;
    if (k>n) return 0;
    ll num=1, den=1;
    for (int i=0; i<k; ++i) num*=(n-i);
    for (int i=1; i<=k; ++i) den*=i;
    return (num/den);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll K;
    cin >> K;
    ll ans=0;    
    int n=s.length();
    ll nonzero=0;
    loop(i,0,n)
    {
        int d1 = s[i]-'0';
        if (d1==0) continue;
        // cout << d1 << " " << nonzero << endl;
        d1--;
        if (K-nonzero-1 >=0 ) {
            ans += (d1*pow(9, K-nonzero-1)*choose(n-i-1, K-nonzero-1));
        }
        if (K-nonzero >=0 ) {
            ans += (pow(9, K-nonzero)*choose(n-i-1, K-nonzero));
        }
        nonzero++;
    }
    if (nonzero==K) ans++;
    cout << ans << "\n";
    return 0;
}