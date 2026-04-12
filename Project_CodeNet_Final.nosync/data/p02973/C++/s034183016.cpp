#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,a,ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++)v.push_back(-1);
     for(int i=0;i<n;i++){
         cin>>a;
         int p=lower_bound(v.begin(),v.end(),a)-v.begin();
         if(v[p-1]==-1)ans++;
         v[p-1]=a;
     }
     cout<<ans<<endl;
}
