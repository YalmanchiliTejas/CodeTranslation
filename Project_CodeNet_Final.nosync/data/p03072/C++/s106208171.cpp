#include<bits/stdc++.h>
using namespace std;

int main(){

 
    int n;
    cin>>n;
    int ans=0;
    int init=-1;
    while(n--){
        int x;
        cin>>x;
        if(x>=init){
            init=x;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}