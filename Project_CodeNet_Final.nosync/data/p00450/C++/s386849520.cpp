#include<stdio.h>
#include<vector>
typedef std::pair<int,int>P;
int main()
{
	int n,i,x;
	while(scanf("%d",&n),n)
	{
		std::vector<std::pair<int,int> >v;
		for(i=0;i<n;++i)
		{
			scanf("%d",&x);
			if(i&1)
			{
				if(v.back().first==x)v.back().second++;
				else
				{
					P p(v.back());v.pop_back();
					if(!v.empty())v.back().second+=1+p.second;
					else v.push_back(P(x,p.second+1));
				}
			}
			else
			{
				if(!v.empty()&&v.back().first==x) v.back().second++;
				else v.push_back(P(x,1));
			}
		}
		for(x=i=0;i<v.size();++i)if(!v[i].first)x+=v[i].second;
		printf("%d\n",x);
	}
	return 0;
}