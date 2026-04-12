#include <bits/stdc++.h>
using namespace std;
int main(){for(int m,n,t;cin>>n,n;){int a[n];for(m=n;t=m--;)cin>>a[m];sort(a,a+n);for(m=n-1;--m;)t+=a[m];cout<<t/(n-2)<<endl;}return 0;}