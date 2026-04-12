/* ***********************************************
Author        :yang12138
Created Time  :2017年07月07日 星期五 16时08分26秒
File Name     :A.cpp
************************************************ */
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int>pii;
#define lson (root<<1)
#define rson (root<<1|1)

const int N=2e5+10;

int ans[N<<1];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int n;
	scanf("%d",&n);

	int l=N,r=N;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i&1) ans[r++]=x;
		else ans[--l]=x;
	}

	if(n&1) reverse(ans+l,ans+r);

	for(int i=l;i<r;i++){
		printf("%d%c",ans[i],i==r-1?'\n':' ');
	}
    
    return 0;
}
