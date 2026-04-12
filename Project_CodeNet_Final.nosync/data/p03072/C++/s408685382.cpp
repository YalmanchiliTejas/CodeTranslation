#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n; cin>>n;
    vector <int> h(n);
    int ans=1;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
    for(int i=1;i<n;i++){
        bool can=true;
        for(int j=0;j<=i-1;j++){
            if(h[i]<h[j]) can=false;
        }
        if(can) ans++;
    }
    cout<<ans<<endl;
}