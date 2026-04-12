#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int p[200];
vector<int>ans;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>p[i];
	int hd=0;
	while(ans.size()<=1e5)
	{
		bool issorted=true;
		for(int i=0;i<N;i++)if(p[(hd+i)%N]!=i)
		{
			issorted=false;
			break;
		}
		if(issorted)break;
		if(p[hd]!=0&&p[hd]<p[(hd+N-1)%N])
		{
			ans.push_back(N-1);
			swap(p[hd],p[(hd+N-1)%N]);
		}
		ans.push_back(1);
		hd=(hd+1)%N;
	}
	if(ans.size()>1e5)return 1;
	cout<<ans.size()<<endl;
	for(int v:ans)cout<<v<<endl;
}
