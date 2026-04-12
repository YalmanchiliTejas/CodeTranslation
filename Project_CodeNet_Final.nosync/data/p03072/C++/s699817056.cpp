#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0,mini=0;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=mini){
            ans++;
            mini=a;
        }
    }
    cout<<ans<<endl;
}