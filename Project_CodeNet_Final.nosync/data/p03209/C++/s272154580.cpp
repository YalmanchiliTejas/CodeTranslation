#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    long n,l;
    long ans;
    double x;
    cin >>n>>x;
    l=n;
    ans=0;
    while(x!=0){
        if(x == pow(2,l+2)-3){
            ans+=long(pow(2,l+1))-1;
            break;
        }
        if(x<pow(2,l+1)-1){
            x-=1;
            l-=1;
        }else{
            x-=pow(2,l+1)-1;
            ans+=long(pow(2,l));
            l-=1;

        }
    }
    cout << ans;
    return 0;

  
    
}