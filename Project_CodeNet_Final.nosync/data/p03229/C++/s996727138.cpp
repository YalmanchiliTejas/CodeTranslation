#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	deque<ll> a(n);
	for(auto &i:a)cin >> i;
	deque<ll> ans;
	sort(a.begin(),a.end());
	ans.push_back(a.back());
	a.pop_back();
	while(a.size())
	{
		vector<pair<int,int>> vp(4);
		vp[0] = make_pair(abs(ans.front()-a.front()),0);
		vp[1] = make_pair(abs(ans.front()-a.back()),1);
		vp[2] = make_pair(abs(ans.back()-a.front()),2);
		vp[3] = make_pair(abs(ans.back()-a.back()),3);
		sort(vp.begin(),vp.end(),greater<>());
		int od = vp.front().second;
		if(od==0)
		{
			ans.push_front(a.front());
			a.pop_front();
		}
		else if(od==1)
		{
			ans.push_front(a.back());
			a.pop_back();
		}
		else if(od==2)
		{
			ans.push_back(a.front());
			a.pop_front();
		}
		else
		{
			ans.push_back(a.back());
			a.pop_back();
		}
	}
	ll out = 0;
	for(int i = 0;i<n-1;i++)
	{
		out+= abs(ans[i]-ans[i+1]);
	}
	cout<<out<<endl;


}
