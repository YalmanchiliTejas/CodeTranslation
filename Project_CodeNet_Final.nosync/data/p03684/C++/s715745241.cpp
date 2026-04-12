#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;

int p[100002];

void init(int n){
    for (int i = 0; i < n; ++i) {
        p[i]=i;
    }
}


int find(int x){
	if(x != p[x]){
		p[x] = find(p[x]);
    }
    return p[x];
    }
     
void union_set(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	p[x]=y;
	return ;
}
int main(){
	int n;
	cin >> n;
	vector<pair<ll,int > > x,y;
	for(int i=0;i<n;i++){
		ll tmpx,tmpy;
		cin >> tmpx >> tmpy;
		x.push_back(make_pair(tmpx,i));
		y.push_back(make_pair(tmpy,i));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	vector<pair<ll,pair<int,int> > > dx,dy;
	for(int i=0;i<n-1;i++){
		dx.push_back(make_pair(x[i+1].first-x[i].first,make_pair(x[i+1].second,x[i].second)));
		dy.push_back(make_pair(y[i+1].first-y[i].first,make_pair(y[i+1].second,y[i].second)));
	}
	sort(dx.begin(),dx.end());
	sort(dy.begin(),dy.end());
	init(n);
	int px=0,py=0;
	bool flag[100001]={};
	ll ans=0;
	while(1){
		if(px==n-1&&py==n-1)break;
		if(px<n-1&&py<n-1){
			if(dx[px].first<=dy[py].first){
				if(find(dx[px].second.first)!=find(dx[px].second.second)){
					union_set(dx[px].second.first,dx[px].second.second);
					ans += dx[px].first;
				}
				px +=1;
			}else{
				if(find(dy[py].second.first)!=find(dy[py].second.second)){
					union_set(dy[py].second.first,dy[py].second.second);
					ans += dy[py].first;
				}
				py +=1;
			}
		}else if(px==n-1){
			if(find(dy[py].second.first)!=find(dy[py].second.second)){
				union_set(dy[py].second.first,dy[py].second.second);
				ans += dy[py].first;
			}
			py +=1;
		}else{
			if(find(dx[px].second.first)!=find(dx[px].second.second)){
				union_set(dx[px].second.first,dx[px].second.second);
				ans += dx[px].first;
			}
			px +=1;
		}
	}
	cout << ans << endl;
	return 0;
}