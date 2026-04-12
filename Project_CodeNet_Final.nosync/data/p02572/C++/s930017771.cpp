#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
long long mod(long long x){
    return (x%M);
    }
long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }

int main()
{  int n;
cin>>n;
int a[n];
for(int i= 0;i<n;i++) cin>>a[i];
vector<long long> v(n+1);
for(int i = n-1;i>=0;i--){
    v[i] = v[i+1] + a[i];
    
}
long long ans = 0;
for(int i = 0;i<n;i++){
    ans = add(ans,mul(a[i],v[i+1]));
}
cout<<ans<<endl;
     
return 0;
   
}