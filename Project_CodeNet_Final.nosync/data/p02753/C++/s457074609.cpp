#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define fi first`
#define se second
const int N=1e5+500;
void solve()
{
	string s;
	cin>>s;
	map<char,ll> lol;
	for(auto i:s)
		lol[i]=1;
	cout<<(lol.size()==1?"No":"Yes");

}

int main()
{


    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
        // cout << endl;
    }

}


