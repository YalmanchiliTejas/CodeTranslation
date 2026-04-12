#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int c=0;
for(int i=0;i<3;i++)
if(s[i]=='A')
c++;
if(c==1||c==2)
cout<<"Yes";
else
cout<<"No";
    
}