#include <iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int main() {
int flag=1;
char str;
cin>>str;
string vowel = "oaiue";
for(int i=0;i<vowel.size();i++){
    if(str==vowel[i]){
        flag=0;
        break;}
}
if(flag==0){
    cout<<"vowel";
}
else
    cout<<"consonant";
}
