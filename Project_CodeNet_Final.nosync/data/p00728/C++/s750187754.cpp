#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n and n){
        int a[n]={};
        int max=-5,min=10000,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<min){
                min=a[i];
            }
            if(a[i]>max){
                max=a[i];
            }
            sum+=a[i];
        }
        int ave=(sum-max-min)/(n-2);
        cout<<ave<<endl;
    }
    return 0;
}

