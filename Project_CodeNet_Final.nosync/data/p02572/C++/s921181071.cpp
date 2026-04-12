#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for (int i = 0; i < n; ++i)
#define tr(i,n) for(auto i=n.begin();i!=n.end();i++)
#define w(t) while(t--)
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fst ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
const ll mod = 1000000007;
void solve()
{
    long long int n;
    cin>>n;
    unsigned long long int arr[n],summ[n];
    fo(i,n)
        cin>>arr[i];
    for(int i=n-1;i>=1;i--)
    {
        if(i==n-1)
        {
            summ[i]=arr[i];
        }
        else
        {
            summ[i]=(summ[i+1]+arr[i])%mod;
        }
    }
    long long int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans+=((arr[i]*summ[i+1])%mod);
        ans=ans%mod;
    }

    cout<<ans%mod;

}

int main()
{
    fst;
    solve();
}