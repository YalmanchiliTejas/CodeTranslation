#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
        b.at(i)=a.at(i);
    }
    sort(b.begin(),b.end());
    int c=b.at(n/2-1);
    for(int i=0;i<n;i++){
        if(a.at(i)<=c)cout<<b.at(n/2)<<endl;
        else cout<<c<<endl;
    }
}