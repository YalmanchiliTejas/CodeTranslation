#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    int tmp = 0;
    vector<int> h(n);
    for(int i=0;i<n;++i){
      cin>>h[i];
    }
    for(int i=0;i<n;++i){
      if(h[i]>=tmp) ans +=1;
      tmp = max(tmp,h[i]);
    }
    cout<<ans<<endl;
}