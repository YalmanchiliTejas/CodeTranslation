#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
vector<int> v;
int main(void){
    cin>>n;
    cin>>a;
    v.push_back(a);
    for(int i=1;i<n;i++){
        cin>>a;
        int L=lower_bound(v.begin(),v.end(),a)-v.begin();
        if(L==0){
            v.insert(v.begin(),a);
        }
        else v[L-1]=a;
    }
    cout<<v.size()<<endl;
}
