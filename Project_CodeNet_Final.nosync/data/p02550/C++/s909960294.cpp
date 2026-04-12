#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll n,x,m;cin>>n>>x>>m;
    ll ans = 0;
    ll tmp = x;
    
    if(x==0){
        cout<<0<<endl;
        return 0;
    }
    if(x==1){
        cout<<n<<endl;
        return 0;
    }
    
    vector<bool>seen(m+1,false);
    
    ll s[m+1];
    s[0]=0;
    s[1]=x;
  ll a[m+1];
    a[0]=x;

    seen[x]=true;
    
    for(ll i=1;i<n;++i){
        tmp*=tmp;
        tmp%=m;
//          cout<<s[i]<<endl;
       if(seen[tmp]==true){
//          cout<<tmp<<endl;
            for(int j=0;j<i;++j){
                if(a[j]==tmp){
                ans=((n-j)/(i-j))*(s[i]-s[j]) + s[j];
                ll n2 = (n-j)%(i-j);
                rep(i2,n2){
                    ans+=tmp;
                    tmp*=tmp;
                    tmp%=m;
                }
//              cout<<i<<" "<<j<<endl;
              cout<<ans<<endl;
                return 0;
            }
        }
       }
        else{
            seen[tmp]=true;
            a[i]=tmp;
            s[i+1]=s[i]+tmp;
        }
    }
//  rep(i,n+1)cout<<s[i]<<endl;
    cout<<s[n]<<endl;
	return 0;
}