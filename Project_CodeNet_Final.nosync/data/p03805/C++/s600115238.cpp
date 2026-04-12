#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int a;
	int b;
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<edge> v(m);
	vector<int> x;
	for(int i = 0; i < m; i++)
	{
		cin >> v[i].a >> v[i].b;
	}
	
	x.push_back(1);
	vector<bool> flag(n,false);
	vector< vector<bool> > tmp_flag;
	int ans = 0;
	
	while(x.empty() == false)
	{
		int tmp = x.back();
		x.pop_back();
		
		flag[tmp - 1] = true;
		
		for(int i = 0; i < n; i++)
		{
			if(flag[i] == false)
			{
				break;
			}
			if(i == n - 1)
			{
				ans++;
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < m; i++)
		{
			if(v[i].a == tmp && flag[v[i].b - 1] == false)
			{
				cnt++;
				x.push_back(v[i].b);
			}
			
			if(v[i].b == tmp && flag[v[i].a - 1] == false)
			{		
				cnt++;
				x.push_back(v[i].a);
			}
		}
		
		if(cnt > 1)
		{
			for(int i = 0; i < cnt - 1; i++)
			{
				tmp_flag.push_back(flag);
			}
		}
		
		if(cnt == 0 && x.empty() == false)
		{
			flag = tmp_flag.back();
			tmp_flag.pop_back();
		}
		
	}
	
	cout << ans << endl;
	return 0;
}