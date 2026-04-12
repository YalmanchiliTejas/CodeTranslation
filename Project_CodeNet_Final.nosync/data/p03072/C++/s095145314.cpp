#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int m=0,sum=0;
    for(int i=0;i<n;i++){
        if(m<=a[i]) sum++;
        m=max(m,a[i]);
    }
    cout<<sum;
}
