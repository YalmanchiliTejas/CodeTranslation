#include<bits/stdc++.h>
#define pb push_back
#define in insert
#define ff first
#define ss second
#define mp make_pair
#define int long long
#define uint unsigned long long
#define rep(i,x,m) for(int i=x;i<m;i++)
#define repr(i,x,m) for(int i=x;i>=m;i--)
#define MOD 1000000007
#define endl "\n"
using namespace std;
#define noob ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void ram5564()
{
    string s;
    cin>>s;
    set<char>set;
    for(auto x:s)
    {
    	set.in(x);
    }
    if(set.size()==2)
    	cout<<"Yes";
    else
    	cout<<"No";

}

signed main()
{
		noob
		
        int t=1;
        //cin>>t;
        while(t--)
        ram5564();
        return 0;
}