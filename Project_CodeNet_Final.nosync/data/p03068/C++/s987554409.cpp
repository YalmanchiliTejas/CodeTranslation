#include <bits/stdc++.h>
using namespace std; 
int main(){
int n,k;
string s;
cin>>n;
cin>>s;
cin>>k;
char check=s[k-1];
for(int i=0; i<n; i++){
if(s[i]!=check)  s[i] = '*';
}
cout<<s<<endl;
}