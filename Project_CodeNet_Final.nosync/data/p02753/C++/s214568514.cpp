#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    set<char> se;
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++) se.insert(s[i]);
    if(se.size()==2) cout<<"Yes";
    else cout<<"No";
}