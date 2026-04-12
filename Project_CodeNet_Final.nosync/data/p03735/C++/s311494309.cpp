#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
typedef long long int LL;
const int INF=1e9+7;
vector<pair<LL,LL> > v1;
int main(){
	int n;
	cin>>n;
	long long int a=INF,b=0,c=INF,d=0;
	int i,j,k;
	long long int e,f;
	long long int s1,s2;
	for(i=0;i<n;i++){
		cin>>e>>f;
		if(e>f)swap(e,f);
		if(a>e)a=e;//min
		if(b<f)b=f;//max
		if(c>f)c=f;//large.min
		if(d<e)d=e;//small.max
		v1.push_back(make_pair(e,f));
	}
	s2=(b-c)*(d-a);
	s1=b-a;
	sort(v1.begin(),v1.end());
	for(i=0,e=d-a;i<n-1;i++){
		d=max(d,v1[i].second);
		a=min(v1[i+1].first,c);
		if(e>d-a)e=d-a;
	}
	s1*=e;
	if(s1>s2)s1=s2;
	cout<<s1<<endl;
	return 0;
}
	
