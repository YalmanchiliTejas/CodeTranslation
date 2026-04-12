#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{    int a=0,b=0;
    string str;
    cin>>str;
for(int i=0;i<str.size();i++){
    if(str[i]=='A') a++;
    else b++;
}
if(a>0 && b>0) cout<<"Yes"<<endl;
else  cout<<"No"<<endl;
   }