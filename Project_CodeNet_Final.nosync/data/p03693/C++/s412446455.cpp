#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main () {
 int r,g,b;
 cin >>r>>g>>b;
 int set =r*100+g*10+b;
 if(set%4 ==0){
   cout<<"YES"<<endl;
 }else{
   cout<<"NO"<<endl;
 }
 
}
