#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<complex>
#include<stack>
#include<cmath>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int main(){
	
	typedef pair<int,int> pii;
	
	vector<pii> dat;
	int a,b;
	int cnt = 0;
	while(scanf("%d,%d",&a,&b)!=EOF){
		if(a==0 && b==0)break;
		dat.push_back(pii(b,a));
		cnt++;
	}
	
	sort(dat.begin(),dat.end());
	reverse(dat.begin(),dat.end());
	
	int rank[11111]={0};
	int r = 1;
	rank[0]=1;
	reps(i,1,dat.size()){
		if(dat[i].first==dat[i-1].first)rank[i]=r;
		else{
			r++;
			rank[i]=r;
		}
	}
	
	
	int c;
	while(cin>>c){
		rep(i,dat.size()){
			if(dat[i].second==c)printf("%d\n",rank[i]);
		}
	}
	
}