#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

set<int> g[100005];
int n;

queue<pair<int,int> > q;
set<pair<int,int> > e;

bool asd(int x, int y){
	if(x>y)swap(x,y);
	if(e.count(mp(x,y)))return true;
	e.insert(mp(x,y));
	return false;
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].insert(y);
		g[y].insert(x);
	}
	if(n==2){puts("Second");return 0;}
	fore(x,0,n)if(g[x].size()==1){
		int y=*g[x].begin();
		if(g[y].size()<=2)q.push(mp(x,y));
	}
	int r=n;
	while(!q.empty()){
		int x=q.front().fst,y=q.front().snd;q.pop();
		if(asd(x,y))continue;
		g[x].erase(y);g[y].erase(x);r-=2;
		for(auto z:g[x]){
			g[z].erase(x);
			if(g[z].size()==1){
				int zz=*g[z].begin();
				if(g[zz].size()<=2)q.push(mp(z,zz));
			}
			else if(g[z].size()==2){
				auto it=g[z].begin();
				int zz=*it;
				if(g[zz].size()==1)q.push(mp(z,zz));
				else {
					++it;
					zz=*it;
					if(g[zz].size()==1)q.push(mp(z,zz));
				}
			}
		}
		g[x].clear();
		for(auto z:g[y]){
			g[z].erase(y);
			if(g[z].size()==1){
				int zz=*g[z].begin();
				if(g[zz].size()<=2)q.push(mp(z,zz));
			}
			else if(g[z].size()==2){
				auto it=g[z].begin();
				int zz=*it;
				if(g[zz].size()==1)q.push(mp(z,zz));
				else {
					++it;
					zz=*it;
					if(g[zz].size()==1)q.push(mp(z,zz));
				}
			}
		}
		g[y].clear();
	}
	puts(r?"First":"Second");
	return 0;
}