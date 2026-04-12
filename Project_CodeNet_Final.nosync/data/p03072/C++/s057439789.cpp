#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int h[101];
    cin>>n;
    for(int i=0;i<n;i++) cin>>h[i];
    int mn=h[0];
    int sum=1;
    for(int i=1;i<n;i++){
        if(mn>h[i]) continue;
        sum++;
        mn=max(mn,h[i]);
    }
    cout<<sum<<endl;
    return 0;
}

