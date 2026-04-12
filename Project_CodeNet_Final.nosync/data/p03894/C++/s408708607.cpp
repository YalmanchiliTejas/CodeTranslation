#include<iostream>
#include<set>
using namespace std;
int N,Q,id[1<<17];
set<int>S;
main()
{
	cin>>N>>Q;
	int now=1;
	S.insert(1);
	S.insert(2);
	for(int i=1;i<=N;i++)id[i]=i;
	for(int i=0;i<Q;i++)
	{
		int a,b;cin>>a>>b;
		if(a==now)now=b;
		else if(b==now)now=a;
		swap(id[a],id[b]);
		if(now>1)S.insert(id[now-1]);
		if(now<N)S.insert(id[now+1]);
	}
	cout<<S.size()<<endl;
}