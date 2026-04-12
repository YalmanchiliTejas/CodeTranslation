#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using ll=long long;


struct city_t
{
	int x, y;
	int rx, ry;
	int id, passed;
};


vector<city_t> vcity;
vector<int> xrank2id, yrank2id;
int n;


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


ll solve(void)
{
	priority_queue<que_t> q;
	int id=0;
	ll cost=0;
	ll ans=0;

	q.push(que_t(id, cost));
	while(!q.empty())
	{
		int rank, rid;

		id=q.top().m_id;
		cost=q.top().m_cost;
		q.pop();

		if(vcity[id].passed) continue;
		vcity[id].passed=1;
		ans+=cost;

		rank=vcity[id].rx-1;
		if(rank>=0)
		{
			rid=xrank2id[rank];
			if(!vcity[rid].passed)
			{
				q.push(que_t(rid, distance(vcity[id], vcity[rid])));
			}
		}

		rank=vcity[id].rx+1;
		if(rank<n)
		{
			rid=xrank2id[rank];
			if(!vcity[rid].passed)
			{
				q.push(que_t(rid, distance(vcity[id], vcity[rid])));
			}
		}

		rank=vcity[id].ry-1;
		if(rank>=0)
		{
			rid=yrank2id[rank];
			if(!vcity[rid].passed)
			{
				q.push(que_t(rid, distance(vcity[id], vcity[rid])));
			}
		}

		rank=vcity[id].ry+1;
		if(rank<n)
		{
			rid=yrank2id[rank];
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
	while(scanf("%d", &n)==1)
	{
		vcity.resize(n);
		xrank2id.resize(n);
		yrank2id.resize(n);

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
				xrank2id[i]=temp[i].id;
				vcity[temp[i].id].rx=i;
			}
			sort(temp.begin(), temp.end(), y_cmp);
			for(int i=0;i<n;i++)
			{
				yrank2id[i]=temp[i].id;
				vcity[temp[i].id].ry=i;
			}
		}

		printf("%lld\n", solve());
	}

	return 0;
}
