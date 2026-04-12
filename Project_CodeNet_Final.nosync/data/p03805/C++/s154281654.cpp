#include <bits/stdc++.h>
using namespace std;

int print_stderr_permutation(vector<int> &v);

int main()
{
	int n,m;
	cin >> n >> m;

	vector<int> a(m);
	vector<int> b(m);
	for (int i=0;i<m;++i)
	{
		cin >> a.at(i) >> b.at(i);
	}

	vector<int> p(n);
	for (int i=0;i<n;++i)
	{
		p.at(i)=i+1;
	}

	int count=0;
	do
	{
		//print_stderr_permutation(p);

		if (p[0]!=1)
		{
			continue;
		}

		int i,j;
		for (i=0;i<n-1;++i)
		{
			int aa=p[i];
			int bb=p[i+1];
			for (j=0;j<m;++j)
			{
				if ( ((a[j]==aa)&&(b[j]==bb)) || ((a[j]==bb)&&(b[j]==aa)) )
				{
					break;
				}
			}
			if (j>=m)
			{
				break;
			}
		}
		if (i>=n-1)
		{
			//fprintf(stderr," -> meets condition\n");
			++count;
		}

	}
	while (next_permutation(p.begin(),p.end()));

	cout << count << endl;

}


int print_stderr_permutation(vector<int> &v)
{
	int size=v.size();
	fprintf(stderr,"trying ");
	for (int i=0;i<size;++i)
	{
		fprintf(stderr,"%d ",v[i]);
	}
	fprintf(stderr,"\n");
	return 0;
}

