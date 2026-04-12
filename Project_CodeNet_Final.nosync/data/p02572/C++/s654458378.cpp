/*
   Username : moondancer
   Name : Moon Dancer
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

int modInverse(int A,int m)
{
    return pw(A,m-2,m);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int m1=1e9+7;
    int x1=0,x2=0;
    for (int i = 0; i < n; ++i)
    {
        x1=(x1+a[i])%m1;
        x2=(x2+(a[i]*a[i])%m1)%m1;
    }
    x1=(x1*x1)%m1;
    int ans=(x1-x2+m1)%m1;
    cout<<(ans*modInverse(2,m1))%m1;
    return 0;
}