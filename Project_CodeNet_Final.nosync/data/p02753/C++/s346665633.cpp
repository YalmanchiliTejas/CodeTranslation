#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int main(){
string s;cin>>s;int ok=0;
if(s[0]!=s[1]&&s[1]!=s[2]) ok=1;
else if(s[0]!=s[1]&&s[0]!=s[2]) ok=1;
else if(s[2]!=s[1]&&s[2]!=s[0]) ok=1;
if(ok) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}
