	#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/rope>

 

#define ll long long

#define pb push_back

#define sz(x) (int)(x).size()

#define mp make_pair

#define all(x) x.begin(), x.end()

 

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<ll> stk;
	while(n--)
	{
		ll a;
		cin >> a;
		//cout << a << endl;
		stk.push_back(a);
		int q=stk.size();
		while(q>2&&stk[q-1]<=stk[q-2]&&stk[q-3]<=stk[q-2])
		{
			ll ne=stk[q-1]+stk[q-3]-stk[q-2];
			for(int i=0;i<3;i++)
			stk.pop_back();
			stk.push_back(ne);
			q-=2;
		}
	}
	ll sum=0;
	deque<ll> q;
	for(auto p:stk)
	q.push_back(p);
	int z=1;
	while(q.size())
	{
		if(q.front()>=q.back())
		{
			sum+=q.front()*z;
			q.pop_front();
		}
		else
		{
			sum+=q.back()*z;
			q.pop_back();
		}
		z*=-1;
	}
	cout << sum;
}
    
