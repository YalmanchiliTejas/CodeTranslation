#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>s;
int n,a,L;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        L=lower_bound(s.begin(),s.end(),a)-s.begin();
        if(!L)s.insert(s.begin(),a);
        else s[L-1]=a;
    }
    cout<<s.size()<<endl;
}
