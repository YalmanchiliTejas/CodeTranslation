#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x7fffffff;
const int mod=1e9+7;
const int eps=1e-6;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
signed main()
{
    IOS;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
