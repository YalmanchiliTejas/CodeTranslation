#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum=0;
    long long a[n];
    long long b[n];
    int i,j;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    b[n-1]=a[n-1];
    for(i=n-2;i>=0;i--){
        b[i]=(a[i]+b[i+1])% (1000000007);
    }
    for(i=0;i<n-1;i++){
        sum =(sum + a[i]*b[i+1])% (1000000007);
    }
    cout << sum << endl;
    return 0;
}