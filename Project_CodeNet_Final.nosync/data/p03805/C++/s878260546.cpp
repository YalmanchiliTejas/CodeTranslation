#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
vector <int> ve[10];
int n,m,sum;
vector <int> k;
bool used[10];
void dfs(int x){
	used[x]=true;
	k.push_back(x);
	if (k.size()==n) sum++; 
	for (int i=0;i<ve[x].size();i++) if (!used[ve[x][i]]) dfs(ve[x][i]);
	k.pop_back(); 
	used[x]=false;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		ve[a].push_back(b);
		ve[b].push_back(a);  
	}
	dfs(1);
	cout<<sum;
	return 0;
}