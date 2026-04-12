#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int n,a,b;
	int count[100001]={};
	vector<int> v[100001];
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		count[a]+=1;
		count[b]+=1;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(count[i]==1){
			q.push(i);
		}
	}
	int x,y;
	int black=0;
	int flag[100001]={};
	while(!q.empty()){
		x = q.front();
		if(flag[x]==1){
			q.pop();
			continue;
		}
		flag[x]=1;
		black+=1;
		q.pop();
		y = 0;
		for(int i=0;i<v[x].size();i++){
			if(flag[v[x][i]]==0){
				y = v[x][i];
				flag[y]=1;
				for(int i=0;i<v[y].size();i++){
					if(flag[v[y][i]]==0){
						count[v[y][i]]-=1;
						if(count[v[y][i]]==1){
							q.push(v[y][i]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0)black+=1;
	}
	if(black>n/2)cout << "First" <<endl;
	else cout <<"Second" << endl;
	return 0;
}