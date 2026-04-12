#include <bits/stdc++.h>
#include <iostream>
using namespace  std;

int main() {

 string str;
 cin>>str;
 int counta=0,countb=0;
 for(int i=0;i<str.size();i++){
     if(str[i]=='A')counta++;
     else countb++;

 }

if(counta==0 || countb==0 || counta==3 || counta==3){cout<<"No";}
else {cout<<"Yes";}
    return 0;
}