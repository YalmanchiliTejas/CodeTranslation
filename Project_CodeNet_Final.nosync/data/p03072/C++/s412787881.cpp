#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans=0;
    int tmp;
    vector<int>d(n);
    for(int i=0;i<n;i++){
    cin>>d.at(i);
    }
    int ma=d.at(0);
    for(int i=0;i<n;i++){
        if(ma<=d.at(i)){
        ma=d.at(i);
        ans++;}
    }
  cout<<ans<<endl;
  }
