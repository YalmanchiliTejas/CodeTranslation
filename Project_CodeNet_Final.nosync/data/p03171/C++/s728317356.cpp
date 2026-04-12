#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define fr1(i,a,b) for(ll i=a; i>=b; i--)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define input(a,n) fr(i,0,n)cin>>a[i]
#define output(a,n) fr(i,0,n)cout<<a[i]<<" "
#define dbg cout<<"hurr"<<endl;
#define dbg2 cout<<"hurr2"<<endl;
#define md 1000000007
#define sp << " " <<
#define pi 3.14159265358979323846
#define fixd(x) cout << fixed << setprecision(x);

int main()
{
    fast;
    ll n;
    cin >> n;
    ll a[n+1],dp[n+1][n+1];
    fr(i,1,n+1)
        cin >> a[i];
    fr(i,0,n+1)
    {
        fr(j,1,n+1)
        {
            ll k=j+i;
            if(k>n)
                break;
            if(j==k)
                dp[j][k]=a[j];
            else if(a[j]-dp[j+1][k]>a[k]-dp[j][k-1])
                dp[j][k]=a[j]-dp[j+1][k];
            else
                dp[j][k]=a[k]-dp[j][k-1];
        }
    }
    cout << dp[1][n];
}