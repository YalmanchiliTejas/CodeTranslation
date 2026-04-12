
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	stack<string>stc[100];
	string s,c,t[1000],k;
	int i = 0,count = 0,n,b;
	cin>>n;

	while(1)
	{
		cin>>s;
		if(s == "quit")break;
		else if(s == "push"){
			cin>>b>>c;
			stc[b].push(c);
		}
		else if(s == "move"){
			cin>>b;
			k = stc[b].top();
			stc[b].pop();
			cin>>b;
			stc[b].push(k);
		}
		else if(s == "pop"){
			cin>>b;
			t[i] = stc[b].top();
			stc[b].pop();
			i++;
			count++;
		}
	}

	for(int j=0; j<count; j++)
		cout<<t[j]<<endl;
	
	return 0;

}