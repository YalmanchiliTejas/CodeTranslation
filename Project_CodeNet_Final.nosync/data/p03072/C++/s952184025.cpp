#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0,c=0;
    cin>>n;
    vector<int> h(n);
    for (int i=0;i<n;i++){
        cin>>h[i];
        c=0;
        for (int j=0;j<i;j++){
            if (h[i]<h[j]){
                c=1;
                break;
            }
        }
        if (c==0){
            ans++;
        }
    }
    cout<<ans<<endl;
}