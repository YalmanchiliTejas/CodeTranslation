#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n,p,p1,p2;
	cin>>n;
	vector<stack<string> > block;
	block.resize(n);
	vector<string> rem;
	string inp,kind;

	while(1)
	{
		cin>>inp;

		if(inp=="quit")break;

		if(inp=="push")
		{
			cin>>p>>kind;
			block[p-1].push(kind);
		}

		if(inp=="pop")
		{
			cin>>p;
			rem.push_back(block[p-1].top());
			block[p-1].pop();
		}

		if(inp=="move")
		{
			cin>>p1>>p2;
			block[p2-1].push(block[p1-1].top());
			block[p1-1].pop();
		}
	}
	for(int i=0;i<rem.size();i++)
		cout<<rem[i]<<endl;
}

//大文字を小文字に変換
/*
for(int i=0;i<inp.size();i++)
if(inp[i]>='A' && inp[i]<='Z')
inp[i]+='a'-'A';
*/