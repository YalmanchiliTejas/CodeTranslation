#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

#define MP make_pair 
#define PB push_back 
#define PH push

int n;
pair<int,int> x[100100],y[100100];
vector<pair<int,int> > vec[100100];     //距离 位置 
set<pair<int,int> > s;
int visit[100100];
int ans=0;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		x[i]=MP(a,i);
		y[i]=MP(b,i); 
	}
	
	sort(x,x+n);
	sort(y,y+n);
	
//for(int i=0;i<n;i++) cout<<x[i].second<<" "; cout<<endl;
//for(int i=0;i<n;i++) cout<<y[i].second<<" "; cout<<endl; 
	
	for(int i=0;i<n;i++)
	{
		int a=x[i].second;
		if(i) vec[a].PB(MP(x[i].first-x[i-1].first,x[i-1].second));
		if(i!=n-1)vec[a].PB(MP(x[i+1].first-x[i].first,x[i+1].second));
		int b=y[i].second;
		if(i) vec[b].PB(MP(y[i].first-y[i-1].first,y[i-1].second));
		if(i!=n-1) vec[b].PB(MP(y[i+1].first-y[i].first,y[i+1].second));
	}
	
	s.insert(MP(0,0));
	while(s.size())
	{
		int a=s.begin()->first;
		int b=s.begin()->second;
		s.erase(s.begin());
		if(visit[b]) continue;
//cout<<a<<" "<<b<<endl; 
		visit[b]=1;
		ans+=a;
		
		for(int i=0;i<vec[b].size();i++)
		{
//cout<<vec[b][i].second;
			if(visit[vec[b][i].second]) continue;
			s.insert(vec[b][i]); 
		}
	} 
	
	cout<<ans<<endl;
	return 0; 
}