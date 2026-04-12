#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    int N,sum,m=0;
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++){
        if(m<a[i]) m=a[i];
        if(m<=a[i]) sum++;
    }
    cout<<sum;
}
