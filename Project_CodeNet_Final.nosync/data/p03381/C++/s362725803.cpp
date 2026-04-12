#include <bits/stdc++.h>

using namespace std;

const int maxn=2e5+5;

int a[maxn];

bool cmp(int i,int j){
    return a[i]<a[j];
}

int main(){
    int n;
    cin>>n;
    int index[n];
    for(int i=0;i<n;i++){
        index[i]=i;
        cin>>a[i];
    }
    sort(index,index+n,cmp);
    for(int i=0;i<n;i++){
        if(a[i]>=a[index[n/2]]){
            cout<<a[index[n/2-1]]<<endl;
        }
        else{
            cout<<a[index[n/2]]<<endl;
        }
    }
    return 0;
}