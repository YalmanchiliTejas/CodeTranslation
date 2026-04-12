#include<bits/stdc++.h>
using namespace  std;

typedef  long long int ll;
typedef  vector<int> vi;
#define  IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define  pb push_back
#define  fn for(int i=0;i<n;i++)
#define  all(x) x.begin(), x.end()
#define  endl "\n"


void solve()
{
	// write your code here :
string s;
	cin>>s;
	if(s[0]==s[1] and s[1]==s[2])
		cout<<"No";
	else cout<<"Yes";
  cout<<endl;
}

int main()
{
	IOS
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
	// int t;
	// cin>>t;
	// while(t--)
	solve();
}
