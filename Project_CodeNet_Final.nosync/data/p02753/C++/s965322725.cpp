#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
int main(){
fast
string s;
cin>>s;
if(s[0]==s[1]&& s[1]==s[2])
{
cout<<"No";
}
else 
cout<<"Yes";
return 0;
}