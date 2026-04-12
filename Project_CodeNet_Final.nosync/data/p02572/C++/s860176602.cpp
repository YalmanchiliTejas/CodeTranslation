#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define all(c) (c).begin(),(c).end()
#define sz(x) (int)(x).size()
#define EPS 0.000000001 //1e-9
#define pii pair<int,int>
using namespace std;
int32_t main()
{
    IOS;
    int n,s=0,p=1000000000+7;
    cin>>n;
    int a[n+1],b[n+1];
    cin>>a[1];
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>b[i];
        a[i]=a[i-1]+b[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        s+=((((a[n]-a[i])%p)*b[i])%p);
        s=s%p;
    }
    cout << s << endl;
}