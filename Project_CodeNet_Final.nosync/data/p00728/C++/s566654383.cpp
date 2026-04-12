#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,i=0,ans=0,mx=-1,mn=99999999,p;
    while(1){
        cin>>p;
        if(p==0) break;
        for(i=0;i<p;i++){
            cin>>n;
            mx=max(mx,n);
            mn=min(mn,n);
            ans+=n;
        }
        cout<<(ans-mx-mn)/(i-2)<<endl;
        ans=0,mx=-1,mn=99999999;
    }
    return 0;
}
