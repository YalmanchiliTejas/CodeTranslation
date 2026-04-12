#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#include<cmath>
#include<stack>
#include<deque>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=200010,mod=1e9+7;
ll a[N],s[N];
int n;
int main()
{
    //IO;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    ll res=0;
    for(int i=1;i<=n;i++)
        res=(res+(s[n]-s[i])%mod*a[i]%mod)%mod;
    cout<<res<<endl;
    return 0;
}