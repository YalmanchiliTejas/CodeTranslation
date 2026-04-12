#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	vector<int >a,b;
	int n,temp;
	vector<int>::iterator it;
	while(scanf("%d",&n)!=EOF)
	{
		a.clear();
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if((i+n)%2==0)
			a.push_back(temp);
			else a.insert(a.begin(),temp);
		}
		for(it=a.begin();it!=a.end();it++)
		{
			cout<<*it<<' ';
		}
		cout<<endl;
	}
}