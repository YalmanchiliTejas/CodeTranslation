#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,b,g;
    cin>>r>>b>>g;
    cout<<((100*r+10*b+g)%4?"NO":"YES");
    
    return 0;
}