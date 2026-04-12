#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i,a,n) for(i=a;i<n;i++)
#define rf(i,a,n) for(i=a;i>=n;i--)
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vi vector<int>
#define vll vector<long long>
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define F first
#define S second
#define all(v) begin(v),end(v)
#define mkp make_pair
#define M 1000000007
#define TakeInput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);


using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	//TakeInput
	#endif
	fast;
	int n,m;
	cin >> n >> m;
	if (n == m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
