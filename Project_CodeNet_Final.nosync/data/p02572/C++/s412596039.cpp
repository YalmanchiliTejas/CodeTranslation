#include<iostream>
#include<algorithm>
using namespace std;
long long s[1000009];
long long  b[1000090];
long long  const mod=1e9+7;
int   main(){

    long long  a;
    cin>>a;
    s[0]=0;
    for(long long  i=1;i<=a;i++){
     cin>>b[i];
     s[i]=s[i-1]+b[i];
     s[i]=s[i]%mod;
    }
    long long ans=0;
    for(long long  i=1;i<a;i++){
          ans=ans+b[i]*(s[a]-s[i]+mod)%mod;
          ans=ans%mod;
    }
    cout<<ans<<endl;
    system("pause");


}