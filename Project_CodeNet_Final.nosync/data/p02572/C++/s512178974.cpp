#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define   ll long long int
#define maxn 300005

ll mod=1e9+7;

int main(){
int n;
cin>>n;
vector<ll> a(n);
ll ts=0;
for(int i=0;i<n;i++){
    cin>>a[i];
    ts+=a[i];
}
ll ans=0;
for(int i=0;i<n;i++){
    ts-=a[i];
    ts=ts%mod;
    ans+=(a[i]*ts)%mod;
    ans=ans%mod;
}
cout<<(ans+mod)%mod<<endl;


}
