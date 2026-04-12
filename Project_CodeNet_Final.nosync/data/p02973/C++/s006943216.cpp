#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>b;
    for(int i=0;i<n;i++){
        auto it = lower_bound(b.begin(),b.end(),a[i]);
        if(it == b.begin()) b.insert(it,a[i]);
        else{
          it--;
          *it=a[i];
        }
    }
  
   // for(int i=0;i<b.size();i++)cout<<b[i];
  cout<<b.size();


    
}