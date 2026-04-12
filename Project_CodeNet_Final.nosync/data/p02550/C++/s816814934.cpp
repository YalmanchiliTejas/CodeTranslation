#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n;
	int x,m;
	cin >> n >> x >> m;

	vector<int> firstappear(m);

	int64_t a=x;
	firstappear[a]=1;
	for (int64_t i=2;i<=n;++i)
	{
		a=(a*a)%m;
		if (firstappear[a]==0)
		{
			firstappear[a]=i;
		}
		else
		{
			// todo
			int64_t loopstart=firstappear[a];
			int64_t inloopcount=n-loopstart+1;
			int64_t period=i-loopstart;
			int64_t loopcount=inloopcount/period;
			int64_t residue=inloopcount%period;
#ifdef NEVER_DEFINED
			fprintf(stderr,"loopstart %d\n",loopstart);
			fprintf(stderr,"inloopcount %d\n",inloopcount);
			fprintf(stderr,"period %d\n",period);
			fprintf(stderr,"loopcount %d\n",loopcount);
			fprintf(stderr,"residue %d\n",residue);
#endif
			int64_t sum=0;
			for (int i=0;i<m;++i)
			{
				if (firstappear[i]==0)
				{
					continue;
				}
				else if (firstappear[i]<loopstart)
				{
					sum+=i;
				}
				else if (firstappear[i]<loopstart+residue)
				{
					sum+=(int64_t)i*(loopcount+1);
				}
				else
				{
					sum+=(int64_t)i*loopcount;
				}
			}
			cout << sum << endl;
			return 0;
		}
	}

	int64_t sum=0;
	for (int i=0;i<m;++i)
	{
		if (firstappear[i]!=0)
		{
			sum+=i;
		}
	}
	cout << sum << endl;
}





