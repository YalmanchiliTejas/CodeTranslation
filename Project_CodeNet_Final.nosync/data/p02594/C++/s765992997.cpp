#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int 
#define mk make_pair

int main(){
   int x;cin>>x;
   if(x>=30)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
    return 0;
}
/*int main(){
    ll n,d;
    cin>>n>>d;
    ll x[n],y[n];
    int ans=0;
    d=d*d;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        ll val=x[i]*x[i]+y[i]*y[i];
        if(d>=val)ans++;
    }
    cout<<ans<<endl;
    return 0;
}*/
