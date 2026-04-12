#include<bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------
#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define frepi(a,b) for(int i=a;i<=b;++i)
// --------------------------------------------------------------------------------

void solve_main()
{
    int x;cin>>x;
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/suryakant/input.txt","r",stdin);
		freopen("/home/suryakant/output.txt","w",stdout);
	#endif
	
    int t=1;
    // cin>>t;
    while(t--)
    {
    	solve_main();
    }    
}