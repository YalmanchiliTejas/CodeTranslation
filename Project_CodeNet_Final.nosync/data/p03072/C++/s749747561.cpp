#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m=1;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(h[j]<=h[i]){
                if(j==i-1) m++;
            }else{
                break;
            }
        }
    }
    cout<<m<<endl;
    return 0;
}