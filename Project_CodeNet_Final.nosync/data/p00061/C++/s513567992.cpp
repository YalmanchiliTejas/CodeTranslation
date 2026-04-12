#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

typedef pair<int,pair<int,int> > P;

int main(){
	vector<P> vec;
	while(1){
		int n,point;
		scanf("%d,%d",&n,&point);
		if(n==0 && point==0)break;
		vec.push_back(make_pair(point,make_pair(n,0)));
	}
	sort(vec.begin(),vec.end(),greater<P>());
	int cnt=2;
	vec[0].second.second=1;
	loop(i,1,vec.size()){
		if(vec[i-1].first==vec[i].first){
			vec[i].second.second=vec[i-1].second.second;
		}else{
			vec[i].second.second=cnt;
			cnt++;
		}
	}
	int num;
	while(cin>>num){
		rep(i,vec.size()){
			if(vec[i].second.first==num){
				cout<<vec[i].second.second<<endl;
				break;
			}
		}
	}
	return 0;
}