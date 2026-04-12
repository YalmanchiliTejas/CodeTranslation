/*
                                                                           __                _________
                                                                          /  \              /  ______/
                                                                         /    \            /  /
                                                                        /  __  \          /  /
                                                                       /  /  \  \         |  |
                                                                      /  /____\  \        \  \
                                                                     /  ________  \        \  \______
                                                                    /__/        \__\        \________\
	
	I_love_Hacked;
	I_hate_pretest past;
	
    coder:xxjAc(K) 
    date:2018/3/26 
	    
    I_love_Ac;
    I_hate_WA;
    I_hate_Tle;
    I_hate_RE;
    I_hate_CE;
    I_hate_Mle;
    
    I love Accepts very much;
    
    set
    map
    stack
    queue
    deque
    priority_queue
    vecotr
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int inf=1000000007;
int n;
int x[100007];
int y[100007];
pair<int,int> tx[100007],ty[100007];
int fa[100007];
pair<int,pair<int,int> > b[200007];
int fnd(int x1){
	if (x1==fa[x1]){
		return x1;
	}
	else{
		fa[x1]=fnd(fa[x1]);
		return fa[x1];
	}
}
int zdl(int x1,int y1){
	int t=inf;
	t=min(t,max(x[x1]-x[y1],x[y1]-x[x1]));
	t=min(t,max(y[x1]-y[y1],y[y1]-y[x1]));
	return t;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		tx[i].first=x[i];
		tx[i].second=i;
		ty[i].first=y[i];
		ty[i].second=i;
		fa[i]=i;
	}
	sort(tx,tx+n);
	sort(ty,ty+n);
	for (int i=0;i<n-1;i++){
		b[i*2].first=tx[i+1].first-tx[i].first;
		b[i*2].second.first=tx[i].second;
		b[i*2].second.second=tx[i+1].second;
		b[i*2+1].first=ty[i+1].first-ty[i].first;
		b[i*2+1].second.first=ty[i].second;
		b[i*2+1].second.second=ty[i+1].second;
	}
	sort(b,b+2*n);
	long long ans=0;
	int c=0;
	int x1,y1;
	for (int i=0;i<2*n;i++){
		x1=b[i].second.first;
		y1=b[i].second.second; 
		if (fnd(fa[x1])==fnd(fa[y1])){
			continue;
		}
		else{
			fa[fnd(x1)]=fnd(y1);
			c++;
			ans+=zdl(x1,y1);
			if (c==n-1){
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}