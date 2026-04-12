#include <iostream>
#include <bits/stdc++.h>
#include <set>
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define ll long long
#define ull unsigned long long
#define MAXN 1000000007
#define INF 1e12
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> trip;
typedef pair<ll int,ll int> pli;
typedef vector<int> vi;
typedef vector<ll int> vli;
typedef vector<vi> vvi;
string getString(char x)
{
    string s(1, x);

    return s;
}
int highestPowerof2(ll int n)
{if(n==0)
    return 0;
   int p = (int)log2(n);
   //cout<<p<<"highest"<<endl;
   return p;
}


int main()
{ios::sync_with_stdio(0);
	cin.tie(0);
    int test=1;
    //int cas=
    //cin>>test;
    while(test--)
    {
       int n;cin>>n;
       vli vec(n);
        vli sum(n+1,0);
       for(int i=0;i<n;i++)
        {cin>>vec[i];vec[i]=vec[i]%1000000007;}
       for(int i=0;i<n;i++)
       {
           sum[i+1]=(sum[i]+vec[i])%1000000007;
          // cout<<sum[i+1]<<endl;
       }
       ll int ans=0;
       for(int i=0;i<n;i++)
       {
           //cout<<vec[n]
           ll int k=(((sum[n]+1000000007)-sum[i+1]))%1000000007;
           //cout<<k<<endl;
           k=(k*vec[i])%1000000007;
           ans+=k;
           ans=ans%1000000007;
       }
       cout<<ans<<endl;

    }

}
