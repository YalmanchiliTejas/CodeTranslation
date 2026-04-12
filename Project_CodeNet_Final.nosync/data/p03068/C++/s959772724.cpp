#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 int n;
 cin>>n;
 string s;
 cin>>s;
 int k;
 cin>>k;
 k--;
 char c=s[k];
 for(char& x:s){
  if(x!=c) x='*';
 }
 cout<<s<<endl;
 return 0;
}