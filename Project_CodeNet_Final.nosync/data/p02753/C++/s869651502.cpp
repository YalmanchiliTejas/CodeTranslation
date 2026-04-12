#include<bits/stdc++.h>
using namespace std;
int main(){string s;
int i,a=0,b=0;
cin>>s;
for(i=0;i<3;i++){
    if(s[i]=='A'){a++;}
    else{b++;}
}if(min(a,b)){cout<<"Yes";}
else{cout<<"No";}
    return 0;}