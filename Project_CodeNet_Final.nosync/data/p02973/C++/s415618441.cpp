#include <bits/stdc++.h>
using namespace std;

int n,a[100010];

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> b;
    b.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]<=*b.begin()){
            b.insert(b.begin(),a[i]);
        }
        else{
            *(lower_bound(b.begin(),b.end(),a[i])-1)=a[i];
        }
    }
    cout<<b.size()<<endl;
}