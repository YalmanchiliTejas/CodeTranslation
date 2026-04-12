/*
Author: Racer5x
 ***************************************   UNAUTHORISED COPYING OF CODE PROHIBITED   **********************************
*/
 
/*#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
 
#include<bits/stdc++.h>
#define int         long long
#define double      long double
#define pb          emplace_back
#define pf          emplace_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353 
#define PI          3.141592653589
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX         2000000000000000000
#define M           1000000007
using namespace std;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int power(int x,int n){
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x) % M;
        x=(x*x)% M;
        n=n/2;
    }
    return result % M;
}

int n,arr[3005] = {0};
int dpx[3005][3005], dpy[3005][3005];

int fx(int left, int right);
int fy(int left, int right);

int fx(int left, int right){
    //cout<<" fx -> "<<left<<' '<<right<<" -------> "<<endl;
    if(left>n-1 || right<0) return 0;
    if(left == right){ /*cout<<arr[left]<<endl;*/ return arr[left]; } 
    if(dpx[left][right]>=0){ /*cout<<dpx[left][right]<<endl;*/ return dpx[left][right];} 
    dpx[left][right] = max(arr[left] - fy(left+1, right), arr[right] - fy(left, right-1));
    //cout<<dpx[left][right]<<endl;
    return dpx[left][right];
}

int fy(int left, int right){
   // cout<<" fy -> "<<left<<' '<<right<<" -------> "<<endl;
    if(left>n-1 || right<0) return 0;
    if(left == right){/* cout<<arr[left]<<endl;*/ return arr[left]; } 
    if(dpy[left][right]>=0){/* cout<<dpy[left][right]<<endl; */return dpy[left][right];} 
    dpy[left][right] = max((1)*arr[left] - fx(left+1, right), (1)*arr[right] - fx(left, right-1));
    //cout<<dpy[left][right]<<endl;
    return dpy[left][right];
}

signed main()
{
    tezz
 

    memset(dpx,-1,sizeof(dpx));
    memset(dpy,-1,sizeof(dpy));
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<fx(0,n-1);
}