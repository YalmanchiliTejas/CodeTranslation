#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans=n*800;
    ans-=(n/15)*200;
    cout<<ans<<endl;
    return 0;
}