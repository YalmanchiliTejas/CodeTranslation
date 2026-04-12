#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=1;cin>>n;vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h.at(i);
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=i-1;j>=0;j--){
            if(h.at(i)>=h.at(j)) count++;
        }
        if(count==i) ans++;
    }
    cout<<ans<<endl;
}