#include <bits/stdc++.h>
using namespace std;main(){long long n,b ,k,res=0;cin>>n>>k;if(!k)return cout<<n*n,0;for(b = k+1;b<=n;b++)res+=n/b*max(0LL,b-k)+max(n%b-k+1,0LL);cout << res;}
