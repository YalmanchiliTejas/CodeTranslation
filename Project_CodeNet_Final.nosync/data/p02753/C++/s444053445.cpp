#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+5;
map<char,int>mp;
int main()
{
    string a;
    cin>>a;
    for(int i=0;i<3;i++)
    {
        mp[a[i]]++;
    }
    if(mp['A']&&mp['B'])
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';
}
