#include<iostream>
#include<set>
#include<string.h>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
vector<int> vec;
vector<int>::iterator it;
int n, x, num;
signed main(){
	while (~scanf("%d", &n))
	{
		vec.clear();
		num = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			x = 1e9 + 7 - x;
			if (vec.empty())
			{
				vec.push_back(x);
				num++;
			}
			else
			{
				it = upper_bound(vec.begin(), vec.end(), x);
				if (it == vec.end())
				{
					vec.push_back(x);
					num++;	
				}
				else
				{
					*it = x;
				}	
			}
		}
		printf("%d\n", num);
	}
}
