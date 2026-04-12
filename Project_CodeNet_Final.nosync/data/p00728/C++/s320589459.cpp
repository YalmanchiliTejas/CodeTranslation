#include<bits/stdc++.h>
using namespace std;
typedef long long L;
L n;
int main(){
    while(scanf("%lld",&n)&&n){
        L ar[n+1],sum=0;
        for(L i=0;i<n;i++){
            scanf("%lld",&ar[i]);
        }
        sort(ar,ar+n);
        for(L i=1;i<n-1;i++)sum+=ar[i];
        cout<<sum/(n-2)<<"\n";
    }
    return 0;
}

