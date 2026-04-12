//in the name of allah
#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int , int> ii;
typedef long long ll;

const int maxn = 1e5+10;
int x[maxn] , d[maxn];
bool mark[maxn];
vector<int> g[maxn];

int main(){
	int n;
	scanf("%d" , &n);
	queue<int> q;
	for(int i=0 ; i<n-1 ; i++){
		int a , b;
		scanf("%d%d" , &a , &b);
		a --;
		b --;
		d[a] ++;
		d[b] ++;
		x[a] ^= b;
		x[b] ^= a;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0 ; i<n ; i++)
		if(d[i] == 1)
			q.push(i);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(d[v] == 0){
			puts("First");
			return 0;
		}
		int par = x[v];
		for(auto u : g[par]){
			d[u] --;
			x[u] ^= par;
			if(u != v && d[u] <= 1)
				q.push(u);
		}
	}
	puts("Second");
}
