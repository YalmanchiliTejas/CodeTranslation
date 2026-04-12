#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;


const ll MM = 1e9 + 7;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &i:A)cin >> i;
    ll sum =0,count=0;
    vector<ll> B(N);
    
    for(ll j=N-1;j>=0;j--){
      //  cout << j << endl;
        sum += A[j]%MM;
        sum %= MM;
        B[j]=sum;
        
    }
    
    for(ll i=0;i<N-1;i++){
        count += (A[i]*B[i+1])%MM;
        count %= MM;
       
    }
    
   cout << count << endl;
}
