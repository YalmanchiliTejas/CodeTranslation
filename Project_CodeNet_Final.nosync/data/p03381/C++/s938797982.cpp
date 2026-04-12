#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 5;

struct X{
	int ans,pos;
}a[maxn];

bool cmp(X x,X y){
	if(x.ans == y.ans) return x.pos < y.pos;
	return x.ans < y.ans;
}

int k[maxn];

int main(){
	int n; scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i].ans);
		a[i].pos = i;
	}
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i++){
		int l = i - 1,r = n - i;
		int cnt = (n) / 2;
		if(cnt <= l){
			k[a[i].pos] = a[cnt].ans;
		}
		else{
			k[a[i].pos] = a[cnt + 1].ans;
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d\n",k[i]);
	}
}
