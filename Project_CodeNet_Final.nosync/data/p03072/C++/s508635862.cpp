#include <bits/stdc++.h>
using namespace std;
int n,h[25];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;for(int i=1;i<=n;i++)cin>>h[i];
    int mx = h[1],ans=0;
    for(int i=1;i<=n;i++){
        if(h[i]>=mx){
            mx=h[i];ans++;
        }
    }
    cout<<ans<<endl;
}

