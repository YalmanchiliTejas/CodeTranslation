
#include<bits/stdc++.h>
using namespace std;
int main()
{
 
int a,b,c,i;
set<char>s;
char x;
for(i=1;i<=3;i++){cin>>x;s.insert(x);}
if(s.size()==1)cout<<"No\n";
else cout<<"Yes\n";
}