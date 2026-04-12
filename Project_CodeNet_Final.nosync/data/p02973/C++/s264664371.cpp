#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
//priority_queue<int, vector<int>, greater<int> > pq;
const int N = 300030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    1e9+7;
int main()
{
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n;
cin>>n;
vector<int> v;
vector<int>::iterator it;
rep(i,0,n)
{
	int x;
	cin>>x;
	 it=upper_bound(v.begin(),v.end(),x,greater<>());
	if(it==v.end()) v.push_back(x);
	else *it = x;
}
cout<<v.size();
}





