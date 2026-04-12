#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
string s;cin>>s;
bool ok=false;
rep(i,2){
    if(s[i]!=s[i+1])ok=true;
}
if(s[0]!=s[2])ok=true;
if(ok)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}