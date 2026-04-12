#include<bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7;
int main(){
   int n;
   cin>>n;
   vector<long long>vc(n);
   for(int i = 0; i < n; ++i)cin>>vc[i];
  vector<long long> prefix(n+1, 0);
    for(int i = 1;i <= n; ++i)prefix[i] = prefix[i - 1] + vc[i - 1];
    
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        sum += (vc[i] * ( (prefix[n] - prefix[i + 1])% mod) );
        sum %= mod;
    }
    cout<<sum<<'\n';
    return 0;
}
