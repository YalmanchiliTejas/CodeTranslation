#include <bits/stdc++.h>
using namespace std;
#define int long long
int MAX=1000000007;


signed main() {
    int n;
    cin>>n;
    int s[n];
    for(int i =0;i<n;i++)cin>>s[i];
    int k[n];
    for(int i=0;i<n;i++)k[i]=s[i]+s[n-1-i];
    int ans=0,ans2=0,d=0,p=0;
    for(int i=1;i<n;i++){
        ans2=0;d=0;p=0;
        if((n-1)%i==0){
            d+=i;
            while(2*d<(n-1)){
                p+=k[d];
                if(p>0){
                    ans2+=p;
                    p=0;
                }
                d+=i;
            }
        }else{
            d+=i;
            while(d<n-1-i){
                p+=k[d];
                if(p>0){
                    ans2+=p;
                    p=0;
                }
                d+=i;

            }
        }
        ans=max(ans,ans2);
    }
    cout<<ans;


    return 0;


}
