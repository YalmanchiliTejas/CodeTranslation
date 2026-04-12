#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod=1e9+7;
#define fi0 for(ll i=0;i<n;i++)
ll mode(ll n){
    return ((n%mod)+mod)%mod;
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    fi0 cin>>a[i];
    vector<ll>b(n+1);
    for(ll i=n-1;i>=0;i--){
        b[i]=b[i+1]+a[i];
        b[i]=mode(b[i]);
    }
    ll sum=0;
    for(ll i=1;i<n;i++){
        sum+=(mode(a[i-1])*mode(b[i]));
        sum=mode(sum);
    }
    cout<<sum<<endl;
}
void abc(){
 int i, j, k;
    int n,m;
    int x,y;

    cin>>n;

    ll cnt=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=i^j;

            if(x<=n && x>0)
            {
                k=0;
                if(i+j<=x)
                    k++;
                else if(i+x<=j)
                    k++;
                else if(x+j<=i)
                    k++;

                if(k<=0)
                    cnt++;
            }
        }
    }

    cout<<cnt/6;
}
void bcd(){
    string s,ss;
    cin>>s>>ss;
    int sum=0,n=s.size(),nn=ss.size();
    for(int i=0;i<=n-nn;i++){
            int a=0;
        for(int j=i;j<i+nn;j++){
            if(s[j]==ss[j-i]){
                a++;
            }
           /// cout<<s[j]<<ss[j]<<' ';

        }
        sum=max(a,sum);
       /// cout<<sum<<endl;
    }
    cout<<ss.size()-sum<<endl;
}
int main()
{
   ///int t;cin>>t;while(t--){
    solve();
    return 0;
}
