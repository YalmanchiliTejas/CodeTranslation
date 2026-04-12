#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>

using namespace std;

typedef pair<int,int> pii;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<=k;i++)


int main(){
	int n,p,r[101],cnt;
	vector<pii> v;
	for(;;){
		scanf("%d,%d",&n,&p);
		if(n==0&&p==0)break;
		v.push_back(pii(p,n));
	}
	sort(v.rbegin(),v.rend());
	cnt=0;
	int s = v.size();
	rep(i,s){
		if(i>0 && v[i-1].first == v[i].first)cnt++;
		r[v[i].second-1]=i+1-cnt;
	}
	while(~scanf("%d",&n))printf("%d\n",r[n-1]);
	
	return 0;
}