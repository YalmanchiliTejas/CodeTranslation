/*  CREATED BY
    STREAM_CIPHER
    29-aug-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout << fixed << setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a)
        	cin>>i;
        int suf[n+1]={0};
        suf[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
        	suf[i]+=suf[i+1]+a[i];
        	suf[i]%=mod;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
        	// debug2(a[i],suf[i+1]);
        	ans+=(a[i]*suf[i+1])%mod;
        	ans%=mod;
        }
        cout<<ans<<endl;

}