#include <bits/stdc++.h>
using namespace std;
int main(){
string s;cin>>s;
int count=0;
if(s[0]!=s[1])count++;
if(s[1]!=s[2])count++;
if(count==0)cout<<"No"<<endl;
else cout<<"Yes"<<endl;

}