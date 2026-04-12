#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    int h[n];
    int i;
    for(i=0;i<n;i++)
    cin>>h[i];
    int max=h[0];
    for(i=0;i<n;i++){
        if(h[i]>=max)
        {
            count++;
            max=h[i];
        }
    }
    cout<<count<<endl;

}