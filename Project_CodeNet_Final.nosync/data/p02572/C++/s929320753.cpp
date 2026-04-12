/*Anup Ghosh*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(-1)
#define ull unsigned long long
#define nl printf("\n")
#define MAXN 1000005
#define mod  1000000007
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define fio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sp(n)  fixed<<setprecision(n)
int main() 
{
	fio();
    int n,i;
    cin >> n;
    int a[n];
    ll sum = 0;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        sum +=a[i];
        sum %=mod;
    }
    ll ans = 0;
    for (i=0;i<n;i++)
    {
        sum -= a[i];
        if (sum<0) sum += mod;
        ans += a[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
return 0;
}