//AUTHOR - NIMISH UPADHYAY
//FROM IIIT ALLAHABAD
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define UPADHYAY int t;cin>>t;while(t--) 
#define pb push_back
#define NIMISH ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    ll n;
    cin>>n;
    ll c[n+1]={0},v[n+1],k=0,p=1e9+7,i;
    for(i=1;i<=n;i++){
        cin>>v[i];
        c[i]=(c[i-1]+v[i])%p;
    }
    for(i=1;i<=n;i++){
        k=(k+(v[i]*((c[n]-c[i]+p)%p))%p)%p;
    }
    cout<<k;
}