#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,x;
    cin>>n;
    int maxx=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>=maxx){
            ans++;
            maxx=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}