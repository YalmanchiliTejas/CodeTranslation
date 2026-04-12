#include<bits/stdc++.h>
using namespace std;

int n, a[202020], ans[202020];

int main(){
cin >> n;
for(int i =1; i<=n ; i++){
    cin >> a[i];
}
if(n%2==1){
    int x = n/2 +1;
    ans[x]=a[1];
    int t = 2;
    for(int i =1; i<x; i++){
        ans[x+i]=a[t++];
        ans[x-i]=a[t++];
    }
}
if(n%2==0){
    int x = n/2 +1;
    ans[x]=a[1];
    int t = 2;
    for(int i =1;i<x; i++){
        ans[x-i]=a[t++];
        if(t>n)break;
        ans[x+i]=a[t++];
    }
}
for(int i =1; i<=n; i++){
    cout << ans[i] << " ";
}


return 0;}
