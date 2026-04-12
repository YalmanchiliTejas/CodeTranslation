#include <map>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
string s;
int main()
{
    fast;
    cin>>s;
    for (int i=0;i<=s.size();i++)
       if (s[i]=='A' && s[i+1]=='C')
       {
       	   cout<<"Yes"<<endl;
       	   return 0;
       }
    cout<<"No"<<endl;
    return 0;
}