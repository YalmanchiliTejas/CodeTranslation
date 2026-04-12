#include<bits/stdc++.h>
using namespace std;
int main(){long long m=0,p=0,i;
string s;
cin>>s;
for(i=0;i<3;i++){
    if(s[i]=='A')
    m++;
    if(s[i]=='B')
    p++;
}if(m==0||p==0){
    cout<<"No";
}else
cout<<"Yes";
  return 0;
}
