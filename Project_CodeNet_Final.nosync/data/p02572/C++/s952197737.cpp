#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 200005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,sum=0,ans=0;
    cin>>n;
    for(lint i=1;i<=n;i++){
        lint a;
        cin>>a;
        ans=(ans+(sum*a)%mod)%mod;
        sum=(sum+a)%mod;
    }
    cout<<ans;
    return 0;
}
