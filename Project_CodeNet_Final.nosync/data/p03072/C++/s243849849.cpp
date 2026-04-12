#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    int h[n], max=0;
    for(int i=0; i<n; i++){
        cin>>h[i];
        if(h[i]>=max){
            cnt++;
            max=h[i];
        }
    }
    cout<<cnt<<endl;
}