#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	long long int N;
	cin>>N;
	bool f0=0,f1=0;
	stringstream SS;
	SS<<S;
	long long int ans,num;
	char x;
	SS>>ans;
	vector<long long int>data;
	vector<char>p;
	data.push_back(ans);
	while(SS >> x >> num)
	{
		p.push_back(x);
		data.push_back(num);
		if(x=='*')
		{
			ans*=num;
		} else
		{
			ans+=num;
		}
	}
	if(ans==N)
	{
		f0=1;
	}
	ans=0;
	for(size_t i = 0; i < p.size(); i++)
	{
		if(p[i]=='*')
		{
			data[i+1]*=data[i];
			data[i]=0;
		}
	}
	for(auto z : data)
	{
		ans+=z;
	}
	if(ans == N)
	{
		f1 = 1;
	}
	if(f0&&f1)
	{
		cout<<'U'<<endl;
	} else if(f0)
	{
		cout<<'L'<<endl;
	} else if(f1)
	{
		cout<<'M'<<endl;
	} else
	{
		cout<<'I'<<endl;
	}
	return 0;
}