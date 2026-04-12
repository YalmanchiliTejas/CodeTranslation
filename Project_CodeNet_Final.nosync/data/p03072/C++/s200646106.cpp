#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin>>n;
    
    vector<int> h(n);

    for(int i=0; i<n; i++) cin>>h[i];

    int flag,count =1;

    for(int i=1; i<n; i++){
        flag = 0;
        for(int j=0; j<i; j++){
            
            if(h[i] >= h[j])flag++;
        }
        if(flag == i)count++;
    }

    cout<<count<<endl;

    return 0;
}