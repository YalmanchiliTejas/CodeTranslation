#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
vector<long long> v;
int main(){
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
long long n,q,sum=0; cin>>n;
for(long long i=0;i<n;i++){
    cin>>q;
    sum+=q;
    v.push_back(q);
}
q=0;
for(long long i=0;i<n;i++){
    long long el=v[i];
    sum-=el;
   q+=el*(sum%mod);
   q%=mod;
}
cout<<q<<'\n';
return 0;
}
