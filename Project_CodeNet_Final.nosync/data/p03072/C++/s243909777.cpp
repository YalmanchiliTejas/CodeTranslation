#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;int h[n];for(int i=0;i<n;i++)cin>>h[i];
    int cnt=1;bool flag=true;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
                if(h[i]>=h[j])flag=true;
                else {flag=false;break;}
        }
        cnt+=(flag?1:0);
    }
    cout<<cnt<<endl;
}