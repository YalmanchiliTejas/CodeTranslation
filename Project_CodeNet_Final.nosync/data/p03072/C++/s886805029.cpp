#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    int sum=1;
    int max=h[0];
    for(int i=1;i<n;i++){
        if(max<=h[i]){
            max=h[i];
            sum++;
        }
    }
    cout<<sum<<endl;
}