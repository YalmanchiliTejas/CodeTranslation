#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll a[200005],b[200005];
int main()
{
    /*int  d,t,s;
    cin >> d >> t>> s;
    int dis = s*t;
    if(dis>=d)
        cout << "Yes\n";
    else
        cout << "No\n";*/
    /*string s,t;
    int mn = 1e9;
    cin >> s>> t;
    int n = (int)s.size();
    int m = (int)t.size();
    for(int i=0;i<n-m+1;i++)
    {
        int cur=0,lol=0;
        for(int j=i;j<i+m;j++)
        {
            if(s[j]!=t[cur])
                lol++;
            cur++;
        }
        mn = min(lol,mn);
    }
    cout << mn << endl;*/
    ll n;
    cin >> n;
    for(ll i=1;i<=n;i++)
        {
            cin >> a[i];
            b[i] = a[i];
            b[i]+=b[i-1];
        }
    ll sum=0;
    for(ll i=1;i<n;i++)
    {
        ll num = b[n]-b[i];
        //cout << num << endl;
        num = num%mod;
        sum = (sum+ num*a[i])%mod;
    }
    cout << sum << endl;

}
