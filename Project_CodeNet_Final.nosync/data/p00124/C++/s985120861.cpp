#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>
#include<map>

using namespace std;

typedef pair<int,int> pii;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<=k;i++)


int main(){
	vector<string> s;
	vector<pii> v;
	char c[21];
	int n,w,l,d,p,f=0;
	for(;;){
		scanf("%d",&n);
		if(n==0)break;
		if(f)puts("");
		v.clear();
		s.clear();
		rep(i,n){
			scanf("%s%d%d%d",c,&w,&l,&d);
			p=w*3+d;
			s.push_back(string(c));
			v.push_back(make_pair(p,n-i));
		}
		sort(v.rbegin(),v.rend());
		f=1;
		rep(i,n)printf("%s,%d\n",s[n-v[i].second].c_str(),v[i].first);
	}
	return 0;
}