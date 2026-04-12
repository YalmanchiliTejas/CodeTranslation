#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
    int n,x,maxi,ans=1;
    cin>>n;
    cin>>maxi;
    for(int i=1;i<n;i++){
        cin>>x;
        if(x>=maxi){
            ans++;
            maxi=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}
