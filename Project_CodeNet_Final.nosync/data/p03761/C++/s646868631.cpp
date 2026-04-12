#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
string s[n],t;
for(int i=0;i<n;i++){
cin>>s[i];
sort(s[i].begin(),s[i].end());
}
for(int i=0;i<s[0].size();i++){
bool f=true;
for(int j=1;j<n;j++){
if(!binary_search(s[j].begin(),s[j].end(),s[0][i])){
f=false;
break;
}
}
if(f){
t.push_back(s[0][i]);
for(int j=1;j<n;j++){
for(int k=0;k<s[j].size();k++){
if(s[j][k]==s[0][i]){
s[j][k]='#';
break;
}
}
}
}
}
sort(t.begin(),t.end());
cout<<t;
}