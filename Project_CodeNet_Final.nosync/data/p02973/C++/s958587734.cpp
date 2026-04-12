#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
vector<int> v;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++)v.push_back(-1);
    for(int i=0;i<n;i++){
        cin>>a;
        int L=lower_bound(v.begin(),v.end(),a)-v.begin();
        L--;
        v[L]=a;
    }
    for(int i=0;i<v.size();i++)if(v[i]!=-1)ans++;
    cout<<ans<<endl;
}
