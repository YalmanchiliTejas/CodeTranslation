//submitted by HimJ
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define fr(i,s,e) for(i=s;i<e;i++)
#define ms(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int mxn=1e5;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  int t=1;
  //cin>>t;
    while(t--){
            ll n,k;
            ll ans=0;
    cin>>n>>k;
    ll b;
    fr(b,k+1,n+1)
    {
        ll a=k;
//        ll temp=1ll*(b-k)*(b+k-1);
//        temp/=2;
//        temp=1ll*(b-k)*n-temp;
//        temp/=b;
//        temp+=b-k;
//        ans+=temp;
//        ll num=b-k;
//        ll tn=((n-b+1)/b)+1;

        while(1)
        {
            ll mn=((n-a)/b)+1;
        ll tn=a+(mn-1)*b;
            ll gap=n-tn;
            ll num=b-a;
            if(gap+1>=num)
            {
                ans+=num*mn;
                break;
            }
            else
            {
                ans+=(gap+1)*mn;
                a+=gap+1;
            }
        }
        if(k==0)
            ans-=1;
//        ll temp=b-1+(tn-1)*b;
//        if(temp<n)
//            temp+=b;
//        ll gap=temp-n;
//        temp=0;
//        if(gap<num)
//            {
//                temp=gap;
////ans+=1;
//            }
//        ans+=1l*temp*(tn+1)+1ll*(num-temp)*tn;

//        fr(a,k,b)
//        {
//            ans+=((n-a)/b)+1;
//
//        }
//        if(k==0)
//                ans-=1;
    }
    cout<<ans;

  }
  return 0;
  }

