#include <iostream>
using namespace std;int k,n,s,j,a,m=998244353,d[3001];int main(){cin>>n>>s;while(n--){cin>>a;for(j=s+1;j-->a;)d[j]=(d[j]+d[j-a])%m;d[a]++;d[0]++;k=(k+d[s])%m;}cout<<k;}