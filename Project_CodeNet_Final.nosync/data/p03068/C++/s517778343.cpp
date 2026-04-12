#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n;
cin >> n;
string s;
cin >> s;
int k;
cin >> k;
k--;
for(int i=0;i<s.size();i++){
    if(s.at(i)!=s.at(k))cout<<"*";
    else cout<<s.at(i);
}
cout<<endl;
}
 
