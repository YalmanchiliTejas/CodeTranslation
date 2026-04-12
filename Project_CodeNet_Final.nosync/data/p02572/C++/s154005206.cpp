#include<iostream>
#include<cstring>
using namespace std;
const int N=200010;
const long long Mod=1000000007;
long long a[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    long long ans=0;
    long long sum=0;

    for(int i=0;i<n-1;i++) sum+=a[i];
    
    for(int lab=n-1;lab>0;lab--){
        ans=(ans+((sum%Mod)*a[lab])%Mod)%Mod;
        //cout<<ans<<" "<<a[lab]<<endl;
        sum-=a[lab-1];
        //cout<<sum<<endl;
    }
    
    
    cout<<ans<<endl;
    return 0;
}