#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void)

{
string s;
int a=0,b=0;
cin>>s;
for (int i =0;i<s.length();i++)
{
    if (s[i]=='A')a++;
    else b++;
}
if (a==3 || b==3)cout<<"No";
else cout<<"Yes";

}
