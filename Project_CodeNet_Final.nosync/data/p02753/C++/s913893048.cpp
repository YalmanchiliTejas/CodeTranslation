#include<bits/stdc++.h>

using namespace std;


int main(){
string str;
cin>>str;

int len=str.length();
int cntA=0;
int cntB=0;
for(int i=0;i<len;i++){
   if(str[i]=='A') cntA++;
   if(str[i]=='B') cntB++;
}

if(cntA>0&&cntB>0) cout<<"Yes"<<endl;

else cout<<"No"<<endl;
}