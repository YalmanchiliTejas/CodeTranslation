#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
const double PI=3.14159265359;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int&i:v)cin>>i;
    
    int midpos=n/2-1;
    auto v2=v;
    sort(v.begin(),v.end());
    int m1=v[midpos], m2=v[midpos+1];
    for(int i=0; i<n; i++){
        if(v2[i]<=m1) cout<<m2<<endl;
        else cout<<m1<<endl;
        
    }
   
    
    return 0;
}