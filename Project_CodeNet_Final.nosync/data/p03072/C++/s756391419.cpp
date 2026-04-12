#include<bits/stdc++.h>
using namespace std;

int n,a,mx,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        cin>>a;
        if(a>=mx){
            ans++;
            mx=a;
        }
    }
    cout<<ans<<endl;

    return 0;
}