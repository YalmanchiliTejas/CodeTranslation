#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	stack<char> st[n];
	string in;
	while(1)
	{
		cin>>in;
		if(in=="quit") break;
		else if(in=="push")
		{
			int num; char ch;
			cin>>num>>ch;
			st[num-1].push(ch);
		}
		else if(in=="pop")
		{
			int num;
			cin>>num;
			cout<<st[num-1].top()<<endl;
			st[num-1].pop();
		}
		else
		{
			int n1,n2; cin>>n1>>n2;
			char tmp=st[n1-1].top();
			st[n2-1].push(tmp); 
			st[n1-1].pop();
		}
	}
	return 0;
}