#include <bits/stdc++.h>

using namespace std;

bool ischeck[1000001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t;
	vector <long long int> v;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(),v.end());

	memset(ischeck,false,sizeof(ischeck));
	
	long long int res = 0;
	deque <int> deq;
	
	deq.push_back(v[0]);
	ischeck[0] = true;

	int l = 1;
	int r = n-1;
	bool flag = true;
	while(1)
	{
		if(flag)
		{
			if(ischeck[r]==true)
			{
				break;
			}
			ischeck[r] = true;
			deq.push_back(v[r]);
			r--;
			if(ischeck[r]==true)
			{
				break;
			}
			ischeck[r] = true;
			deq.push_front(v[r]);
			r--;
			flag = false;
		}
		else
		{
			if(ischeck[l]==true)
			{
				break;
			}
			ischeck[l] = true;
			deq.push_back(v[l]);
			l++;
			if(ischeck[l]==true)
			{
				break;
			}
			ischeck[l] = true;
			deq.push_front(v[l]);
			l++;
			flag = true;
		}
	}
	for (deque<int>::size_type i = 1; i < deq.size(); ++i)
	{
		//cout << deq[i] << ' ' << deq[i-1] << '\n';
        res += abs(deq[i-1] - deq[i]);
    }
    deq.clear();
    memset(ischeck,false,sizeof(ischeck));

	deq.push_back(v[n-1]);
	ischeck[n-1] = true;

	l = 0;
	r = n-2;
	flag = false;
	while(1)
	{
		if(flag)
		{
			if(ischeck[r]==true)
			{
				break;
			}
			ischeck[r] = true;
			deq.push_back(v[r]);
			r--;
			if(ischeck[r]==true)
			{
				break;
			}
			ischeck[r] = true;
			deq.push_front(v[r]);
			r--;
			flag = false;
		}
		else
		{
			if(ischeck[l]==true)
			{
				break;
			}
			ischeck[l] = true;
			deq.push_back(v[l]);
			l++;
			if(ischeck[l]==true)
			{
				break;
			}
			ischeck[l] = true;
			deq.push_front(v[l]);
			l++;
			flag = true;
		}		
	}

	/*
	for (deque<int>::size_type i = 0; i < deq.size(); ++i)
	{
		cout << deq[i] << '\n';
    }
    */
 	
	long long int res2 = 0;
	for (deque<int>::size_type i = 1; i < deq.size(); ++i)
	{
		//cout << deq[i] << ' ' << deq[i-1] << '\n';
        res2 += abs(deq[i-1] - deq[i]);
    }

   // cout << res << ' ' << res2 << '\n';
    res = max(res,res2);

    cout << res << '\n';

	return 0;
}
