#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main (){
string s;
int n,k;
cin>>n>>s>>k;
char x = s[k-1];
for(int i = 0;i <n;i++){
if (s[i]!=x) s[i]='*';
cout<<s[i];
}
cout << endl;
return 0;
}
