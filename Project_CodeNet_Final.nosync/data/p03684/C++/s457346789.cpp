#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using ll=long long;
using vi=vector<int>;


struct city_t
{
	int x, y;
	vi e;
	int id, passed;
};


bool x_cmp(city_t& a, city_t& b)
{
	return a.x<b.x;
}


bool y_cmp(city_t& a, city_t& b)
{
	return a.y<b.y;
}


int distance(city_t& a, city_t& b)
{
	return min(abs(a.x-b.x), abs(a.y-b.y));
}


struct que_t
{
	int m_id;
	ll m_cost;
	que_t(int id, int cost):m_id(id),m_cost(cost)
	{
	}
	bool operator<(const que_t&rhs) const
	{
		return m_cost>rhs.m_cost;
	}
};


ll solve(vector<city_t>& vcity)
{
	priority_queue<que_t> q;
	int id=0;
	ll cost=0;
	ll ans=0;

	q.push(que_t(id, cost));
	while(!q.empty())
	{
		id=q.top().m_id;
		cost=q.top().m_cost;
		q.pop();

		if(vcity[id].passed) continue;
		vcity[id].passed=1;
		ans+=cost;

		for(auto rid:vcity[id].e)
		{
			if(!vcity[rid].passed)
			{
				q.push(que_t(rid, distance(vcity[id], vcity[rid])));
			}
		}
	}
	return ans;
}


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vector<city_t> vcity(n);

		for(int i=0;i<n;i++)
		{
			scanf("%d%d", &vcity[i].x, &vcity[i].y);
			vcity[i].id=i;
			vcity[i].passed=0;
		}
		{
			auto temp=vcity;
			sort(temp.begin(), temp.end(), x_cmp);
			for(int i=0;i<n;i++)
			{
				if(i+1<n) vcity[temp[i].id].e.push_back(temp[i+1].id);
				if(i-1>=0) vcity[temp[i].id].e.push_back(temp[i-1].id);
			}
			sort(temp.begin(), temp.end(), y_cmp);
			for(int i=0;i<n;i++)
			{
				if(i+1<n) vcity[temp[i].id].e.push_back(temp[i+1].id);
				if(i-1>=0) vcity[temp[i].id].e.push_back(temp[i-1].id);
			}
		}

		printf("%lld\n", solve(vcity));
	}

	return 0;
}
