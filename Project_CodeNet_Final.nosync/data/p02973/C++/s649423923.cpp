#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>x(1,a[0]);
    for(int i=1;i<n;i++){
        if(x.back()>=a[i])x.push_back(a[i]);
        else x[upper_bound(x.begin(),x.end(),a[i],greater<int>())-x.begin()]=a[i];
    }
    cout<<x.size()<<endl;
    return 0;
}