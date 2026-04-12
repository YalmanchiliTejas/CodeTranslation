#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define en "\n"
#define LL long long
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define mpp make_pair
#define mes(a,b) memset((a),(b),sizeof((a))
typedef map<int,int> MI;
typedef pair<int,int>   PI;
typedef vector<int> VI;
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,ans=0,p,q;
    cin>>n;
    long long int a[n],b[n];
    for(long long int i=0;i<n;i++)
    cin>>a[i];
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        b[i]=a[i]+b[i-1];
    }
    
    for(int i=0;i<n-1;i++)
    {
        p=a[i];
        q=(b[n-1]-b[i]);
        p=p%mod;
        q=q%mod;
        //cout<<p<<" "<<q<<en;
        p=(p*q)%mod;
        //cout<<p<<" ";
        ans=ans+p;
        //cout<<ans<<en;
        ans=ans%mod;
    }
    cout<<ans;
    return 0;
}
