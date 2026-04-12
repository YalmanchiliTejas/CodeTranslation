#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> h(n),m(n);
    for(auto&& w:h)cin>>w;
    m[0]=h[0];
    for(int i=1;i<n;i++)m[i]=max(m[i-1],h[i]);
    int cnt=0;
    for(int i=0;i<n;i++)if(m[i]<=h[i])cnt++;
    cout<<cnt<<endl;
    
}