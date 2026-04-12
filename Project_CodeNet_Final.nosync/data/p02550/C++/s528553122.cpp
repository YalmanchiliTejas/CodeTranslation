#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=998244353;
ll n,x,m;
ll a[100005];
ll y[100005];
ll ans[100005];
ll ANS;
ll s,e;
int main(void){
    cin>>n>>x>>m;
    a[0]=x;
    y[x]=0;
    ans[1]=x;
    //cout<<0<<" "<<x<<endl;
    for(int i=1;i<n;i++){
        a[i]=(a[i-1]*a[i-1])%m;
        if(y[a[i]]>0){
            //cout<<i<<endl;
            s=y[a[i]];
            e=y[a[i-1]];
            //cout<<s<<" "<<e<<endl;
            ANS=ans[i];
            n-=s;
            ANS+=((ans[e+1]-ans[s])*(n/(e-s+1)-1));
            n-=((n/(e-s+1))*(e-s+1));
            for(int j=s;j<s+n;j++){
                ANS+=(ans[j+1]-ans[j]);
            }
            cout<<ANS<<endl;
            return 0;
        }else{
            y[a[i]]=i;
        }
        ans[i+1]=ans[i]+a[i];
        //cout<<i<<" "<<a[i]<<endl;
    }
    cout<<ans[n]<<endl;
    
}
