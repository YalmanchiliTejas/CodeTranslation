#include <bits/stdc++.h>
#define X first
#define Y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 200010;
int n,x,y;
vector<int> v[N];
bool pd[N],flag;
int d[N];

bool dfs(int x,int fa){
	//cout<<x<<endl;
	int t;
	pd[x] = false;
	for(int i = 0;i<v[x].size();i++) if((t=v[x][i])!=fa){
		dfs(t,x);
		if(!pd[t]) pd[x] =true;
	}
}
bool dfs2(int x,int fa,int s){
	//cout<<x<<endl;
  	int t;
  	int cnt = 0;
	if(s==0) cnt++;
	for(int i = 0;i<v[x].size();i++) if((t=v[x][i])!=fa){
		if(!pd[t]) cnt++;
	}
	if(cnt>=2) flag =true;
	for(int i = 0;i<v[x].size();i++) if((t=v[x][i])!=fa){
		int s2;
		if(cnt-(1-pd[t])>0) s2 = 1; else s2 = 0;
		dfs2(t,x,s2);
	}
  
}
int main(){
	scanf("%d",&n);
	if(n==2){
		puts("Second");
		return 0;
	}
	for(int i =0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	dfs(1,0);
	flag =false;
	dfs2(1,0,1);
	
	if(flag) puts("First");else puts("Second");
	return 0;
}