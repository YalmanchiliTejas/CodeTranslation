#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> a2=a;
    sort(a2.begin(),a2.end());
    int l=a2[(n-1)/2];
    int r=a2[n/2];
    for(int i=0;i<n;i++){
        if(a[i]<r){
            cout<<r<<endl;
        }
        else{
            cout<<l<<endl;
        }
    }

    return 0;
}