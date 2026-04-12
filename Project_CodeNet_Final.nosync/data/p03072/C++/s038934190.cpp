#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=1;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h.at(i);
    }
    int m=h.at(0);
    for(int i=1;i<n;i++){
        if(m<=h.at(i)){
            ans+=1;
            m=h.at(i);
        }
        else{
        }
    }
    cout<<ans<<endl;
}