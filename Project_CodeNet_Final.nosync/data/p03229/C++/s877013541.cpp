#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric> 
#include <deque>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	deque<ll> de;
	ll x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		de.push_back(x);
	}
	sort(de.begin(), de.end());
	deque<ll> que, tmp;
	tmp = de;
	que.push_front(de[0]);
	de.pop_front();
	bool flag = false;
	ll cnt = 0;
	for(int i = 1; i < n; i++)
	{
		if(flag == false)
		{
			if(cnt % 2 == 0)
			{
				que.push_front(de.back());
				de.pop_back();
			}
			else
			{
				que.push_back(de.back());
				de.pop_back();
			}
			cnt++;
			if(cnt == 2)
			{
				flag = true;
				cnt = 0;
			}
		}
		else
		{
			if(cnt % 2 == 0)
			{
				que.push_front(de.front());
				de.pop_front();
			}
			else
			{	
				que.push_back(de.front());
				de.pop_front();
			}
			cnt++;
			if(cnt == 2)
			{
				flag = false;
				cnt = 0;
			}
		}
	}
	deque<ll> que2;
	de = tmp;
	reverse(de.begin(), de.end());
	que2.push_front(de[0]);
	de.pop_front();
	cnt = 0;
	flag = false;
	for(int i = 1; i < n; i++)
	{
		if(flag == false)
		{
			if(cnt % 2 == 0)
			{
				que2.push_front(de.back());
				de.pop_back();
			}
			else
			{
				que2.push_back(de.back());
				de.pop_back();
			}
			cnt++;
			if(cnt == 2)
			{
				flag = true;
				cnt = 0;
			}
		}
		else
		{
			if(cnt % 2 == 0)
			{
				que2.push_front(de.front());
				de.pop_front();
			}
			else
			{
				que2.push_back(de.front());
				de.pop_front();
			}
			cnt++;
			if(cnt == 2)
			{
				flag = false;
				cnt = 0;
			}
		}
	}
	ll ans1 = 0, ans2 = 0;
	//cout << que[0] << " ";
	for(int i = 1; i < n; i++)
	{
		//cout << que[i] << " ";
		ans1 += abs(max(que[i], que[i - 1]) - min(que[i], que[i - 1]));
	}
	//cout << endl;
	//cout << que2[0] << " ";
	for(int i = 1; i < n; i++)
	{
		//cout << que2[i] << " ";
		ans2 += abs(max(que2[i], que2[i - 1]) - min(que2[i], que2[i - 1]));
	}
	//cout << endl;
	cout << max(ans1, ans2) << endl;
	return 0;
}

