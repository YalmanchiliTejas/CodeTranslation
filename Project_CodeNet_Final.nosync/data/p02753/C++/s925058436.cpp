#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
//#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
//library begin
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int log(int a){
    int b=a;
    int cnt=0;
    while(b%2==0){
        b/=2;
        cnt++;
    }
    return cnt;
}
int mypow(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int t=mypow(a,b/2);
    if(b%2==0)return (t*t)%mod;
    return (t*t*a)%mod;
}

//library end

signed main(){
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB"){
        puts("No");
    }
    else{
        puts("Yes");
    }
    return 0;
}
