#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int h,w;
int fie[9][9];
bool flag;
bool used[9][9];

void check(int x,int y){
	if(fie[y][x]==0)flag=false;
	used[y][x]=true;
	if(y==h-1 && x==w-1)return;
	int cnt=0;
	if(y<h-1 && fie[y+1][x]==1){
		check(x,y+1);
		cnt++;
	}
	if(x<w-1 && fie[y][x+1]==1){
		check(x+1,y);
		cnt++;
	}
	if(cnt==2 || cnt==0)flag=false;
}

int main(void){
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		string str;
		cin >> str;
		for(int j=0;j<w;j++){
			if(str[j]=='#')fie[i][j]=1;
		}
	}
	memset(used,false,sizeof(used));
	flag=true;
	check(0,0);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(fie[i][j]==1 && !used[i][j])flag=false;
		}
	}
	printf("%s\n",flag?"Possible":"Impossible");
	return 0;
}
