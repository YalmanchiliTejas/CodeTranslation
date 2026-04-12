#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))

using namespace std;
void get(int &v)
{
	char c;
	while((c=getchar())!=EOF&&isdigit(c)==0);
	v=c-'0';
	while((c=getchar())!=EOF&&isdigit(c))
		v=(v<<1)+(v<<3)+c-'0';
	return ;
}
int get()
{
	int v;
	char c;
	while((c=getchar())!=EOF&&isdigit(c)==0);
	v=c-'0';
	while((c=getchar())!=EOF&&isdigit(c))
		v=(v<<1)+(v<<3)+c-'0';
	return v;
}
priority_queue<long long>q;
stack<long long>s;
long long chk(int sz)
{
	long long ans=0,t,tmp;
	while(q.top()>=sz)
	{
		t=q.top();
		q.pop();
		ans+=(tmp=t/sz);
		while(q.size())
		{
			s.push(q.top()+tmp);
			q.pop();
		}
		while(s.size())
		{
			q.push(s.top());
			s.pop();
		}
		q.push(t%sz);
	}/*
	while(q.size())
		cout<<q.top()<<' ',q.pop();
	cout<<endl;*/
	return ans;
}
int main()
{
	int n,i;
	long long x;
	get(n);
	for(i=1;i<=n;i++)
	{
		cin>>x;
		q.push(x);
	}
	cout<<chk(n);
	return 0;
}
//g++ -g cc.cpp -o cc