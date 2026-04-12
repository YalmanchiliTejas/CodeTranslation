#include <bits/stdc++.h>
#define INF 990000000
//
using namespace std;

int main() {
string s;
cin>>s;

set<char> lis;
for(int i=0;i<3;i++)lis.insert(s[i]);

if((int)lis.size()==2)
cout <<"Yes"<<endl;
else
cout <<"No"<<endl;


}




