#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
vector<char> s;
char s1,s2,s3;
cin >>s1>>s2>>s3;
s.push_back(s1);

s.push_back(s2);

s.push_back(s3);
sort(s.begin(),s.end());
if(s.at(0)=='A'&&s.at(1)=='B'||s.at(1)=='A'&&s.at(2)=='B')cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
} 