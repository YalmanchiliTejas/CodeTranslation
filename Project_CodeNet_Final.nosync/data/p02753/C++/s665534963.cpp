#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if (all_of(s.begin(),s.end(),[](char t){return t=='A';}) || all_of(s.begin(),s.end(),[](char t){return t=='B';})){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}