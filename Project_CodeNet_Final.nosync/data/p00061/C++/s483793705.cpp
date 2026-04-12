#include<iostream>
#include<map>
#include<vector>

using namespace std;

class data
{
public:
	int n;
	int score;
	int rank;
};

int main(void)
{
	vector<data> d;
	while(1)
	{
		int a,b;
		char c;
		cin>>a>>c>>b;
		if(a==0&&b==0)break;
		data tmp;
		tmp.n=a;
		tmp.score=b;
		d.push_back(tmp);
	}

	for(int i=0;i<d.size();i++)
	{
		int max=i;
		for(int j=i+1;j<d.size();j++)
		{
			if(d[max].score<d[j].score)
			{
				max=j;
			}
		}
		data tmp=d[i];
		d[i]=d[max];
		d[max]=tmp;
	}
	
	int rank=1;
	int score=d[0].score;
	for(int i=0;i<d.size();i++)
	{
		if(d[i].score!=score){
			score=d[i].score;
			rank++;
		}
		d[i].rank=rank;
	}
	while(1)
	{
		int n;
		cin>>n;
		if(cin.eof())break;
		for(int i=0;i<d.size();i++)
		{
			if(d[i].n==n)
			{
				cout<<d[i].rank<<endl;
				break;
			}
		}
	}
}