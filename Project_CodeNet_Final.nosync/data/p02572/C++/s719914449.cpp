//
// Created by kashi on 27-07-2020.
//
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define Endl endl
#define int long long
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
bool cmps(pair<int,int>p1,pair<int,int>p2) {
    return p1.ss<p2.ss;
}
int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int32_t main() {
    int N=1e9 +7;
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum%=N;
    int ans=0;
    for(int i=0;i<n-1;i++){
        sum-=a[i];
        if(sum<0)
            sum+=N;
        ans+=a[i]*sum;
        ans=ans%N;
    }
    cout<<ans<<Endl;
    return 0;
}
