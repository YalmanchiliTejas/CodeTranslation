#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include <iomanip>

#define rep0(i,N) for(int i=0;i<N;i++)
#define rep1(i,a,N) for(int i=0+a;i<N;i++)
#define lint long long int
#define SIZE 100005

using namespace std;


queue<pair<int,int>> q;
int nowh=0,noww=0;
char str[9][9];
void cal(pair<int,int> a){
	if(str[a.first][a.second+1]=='#'){
			pair<int,int> pp;
			pp.first=a.first;
			pp.second=a.second+1;
			q.push(pp);
		}
		if(str[a.first+1][a.second]=='#'){
			pair<int,int> pp;
			pp.first=a.first+1;
			pp.second=a.second;
			q.push(pp);
		}
}


int main(){
	int h,w,ans=0;
	cin>>h>>w;
	rep0(i,h){
		cin>>str[i];
	}
	rep0(i,h){
		rep0(j,w){
			if(str[i][j]=='#')
				ans++;
		}
	}
	pair<int,int> p;
	p.first=0;
	p.second=0;
	q.push(p);
	pair<int,int> cp;
	cp.first=0;
	cp.first=0;
	while(cp.first!=h-1||cp.second!=w-1){
		q.pop();
		cal(cp);
		if(q.empty()==1){
			cout<<"Impossible";
			return 0;
		}
		cp.first=q.front().first;
		cp.second=q.front().second;
	}
	if(ans==h+w-1)
		cout<<"Possible";
	else
		cout<<"Impossible";
return 0;
}