#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str;
cin>>str;
set<char> s;
for(int i=0;i<str.size();i++)
    s.insert(str[i]);
if(s.size()>1)
{
    cout<<"Yes"<<endl;
}
else
    cout<<"No"<<endl;
    return 0;
}