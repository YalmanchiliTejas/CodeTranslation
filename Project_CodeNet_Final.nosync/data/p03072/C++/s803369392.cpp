#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin>>n;
    int a=n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
    for(int j=1;j<i+1;j++){
        if(b[i-j]<=b[i]){
        }else{a--;
            break;
        }
        
    }}
    cout<<a;
    return 0;
}
