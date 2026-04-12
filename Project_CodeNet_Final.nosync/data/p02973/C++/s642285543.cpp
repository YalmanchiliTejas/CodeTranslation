#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define pb 	push_back
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define mod 1000000007LL
#define F first
#define S second
#define speed ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
const int N=2e3+5;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	deque<int>dq;
	for(int i=0;i<n;i++)
	{
		int p=lower_bound(all(dq),a[i])-dq.begin();
		// cout<<p<<" ";
		if(p==0)dq.push_front(a[i]);
		else dq[p-1]=a[i];
	}
	// for(auto i:dq)cout<<i<<" ";cout<<endl;
	cout<<dq.size()<<endl;
}