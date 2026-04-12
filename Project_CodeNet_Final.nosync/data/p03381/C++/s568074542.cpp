#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[200000],A[200000];
    for(int i=0;i<n;i++){
        cin>>x[i];
        A[i]=x[i];
    }
    sort(x,x+n);
    for(int i=0;i<n;i++){
        if(A[i]<x[n/2]) cout<<x[n/2]<<endl;
        else cout<<x[n/2-1]<<endl;
    }
}