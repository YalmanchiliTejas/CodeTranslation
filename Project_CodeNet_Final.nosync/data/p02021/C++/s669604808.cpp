#include<bits/stdc++.h>
using namespace std;
int n;
int a[10009];
int main() {
    cin>>n;
    int sum=0;
    int m=1234;
    for(int i=1;i<=n;i++){
        cin>>a[i-1];
        sum+=a[i-1];
        m=min(m,sum/i);
    }
    cout<<m<<endl;
}

