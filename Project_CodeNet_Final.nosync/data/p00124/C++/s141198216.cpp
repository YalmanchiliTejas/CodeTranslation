#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

#define	score	first
#define	id		second

using namespace std;

typedef	pair<int,int>	pii;

bool cmp(const pii& a,const pii& b)
{
	if(a.score>b.score)	return true;
	if(a.score==b.score && a.id<b.id)	return true;
	return false;
}

int main()
{
	int n;

	for(int k=0;cin>>n,n;k++){
		if(k>0)	cout<<endl;

		vector<pii> scvec;
		map<int,string> namemap;

		for(int i=0;i<n;i++){
			string name;
			int w,l,d;
			cin>>name>>w>>l>>d;
			scvec.push_back(make_pair(3*w+d,i));
			namemap[i]=name;
		}

		sort(scvec.begin(),scvec.end(),cmp);

		for(int i=0;i<scvec.size();i++){
			cout<<namemap[scvec[i].id]<<","<<scvec[i].score<<endl;
		}
	}

	return 0;
}