#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    long long ans=1;
    for(int i=1;i<n;i++){
        bool ok=true;
        for(int j=i-1;j>=0;j--){
            if(h[i]<h[j]) ok=false;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
}