#include <bits/stdc++.h>
     
#define pll pair <long long,long long>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define vll vector <ll>
#define NFS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl '\n'
#define M 1000000007   
using namespace std;
 
void solve()
{
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    NFS
 	int t=1;
 	//cin>>t;
 	while(t--)
 	{
 		solve();
 	}
    return 0;
}