#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

vector<int> node[9];
int N,M;
int a,b;
int pass=0;
bool done[9]={};
void tansaku(int num);
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	tansaku(1);
	printf("%d\n",pass);
	return 0;
}

void tansaku(int num){
	bool flag=0;
	done[num]=1;
	for(int i=0;i<node[num].size();i++){
		if(!done[node[num][i]]){
			tansaku(node[num][i]);
		}
	}
	for(int i=1;i<=N;i++){
		if(done[i]==0) flag=1;
	}
	if(flag==0) pass++;
	done[num]=0;
}