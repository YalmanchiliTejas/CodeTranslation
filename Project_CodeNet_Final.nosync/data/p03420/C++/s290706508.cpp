#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n,k,ans=0;
    cin>>n>>k;
    if(k==0) cout<<n*n<<endl;
    else{
        for(LL b=k+1;b<=n;b++){
            ans+=(n/b)*(b-k);
            if(n%b>=k)
                ans+=n%b-k+1;
        }
        cout<<ans<<endl;
    }
}
