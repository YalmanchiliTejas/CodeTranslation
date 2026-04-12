#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[3010];
ll s[3010];
int main(){
    ll n, sm;
    while(cin>>n>>sm){
        ll ans=0, mod=998244353;
        for(ll i=0; i<n; ++i){
            // a[i]=i+1;
            scanf("%d",a+i);
        }
      int cnt=0;
      s[0]=1;
        for(ll i=0; i<n; ++i){
          // cout<<i<<":::"<<endl;
            for(int j=sm; j>a[i]; --j){
                s[j]+=s[j-a[i]];
                s[j]%=mod;


            //   cout<<j-a[i]<<" "<<s[j-a[i]].size()<<endl;
            //     for(auto it:s[j-a[i]]){
            //         cout<<"#"<<it.fs<<" "<<it.sc<<endl;
            //         s[j][it.fs]+=it.sc;
            //        ++cnt;
            //         if(j==sm){
            //             ll tmp=(it.fs+1)*(n-i);
            //             tmp*=it.sc;
            //             tmp%=mod;
            //             ans+=tmp;
            //             while(ans>=mod){
            //                 ans-=mod;
            //             }
            //         }
            //     }
            // }
            // s[a[i]][i]+=(n-i);
            // if(a[i]==sm){
            //     ans+=(n-i)*(i+1);
            //     while(ans>=mod){
            //         ans-=mod;
            //     }
            }
            s[a[i]]+=(i+1);
            s[a[i]]%=mod;
            ans+=s[sm];
            ans%=mod;
        }
        ans%=mod;
        // for(int i=0; i<=sm; ++i){
        //     //cnt+=s[i].size();
        // }
      // cout<<cnt<<endl;
        printf("%lld\n",ans);
    }
  return 0;
}


