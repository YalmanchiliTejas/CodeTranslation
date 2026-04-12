#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a;
int b[26]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
int main()
{
cin>>a;
if(b[int(a)-97]==1)cout<<"vowel"<<endl;
else cout<<"consonant"<<endl;
return 0;
}
