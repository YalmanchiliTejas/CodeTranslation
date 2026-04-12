
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp,t, n,j, a[200600],b[200010], ans;
bool cond;
char c;
string s;
int main()
{
    //I am Monim, a tiny creature of Allah
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i] = a[i];
        a[i] = a[i-1]+a[i];
    }

    for(i=1;i<n;i++)
    {
        ans += (b[i]%1000000007)*((a[n]-a[i])%1000000007);
        ans %= 1000000007;
       // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
