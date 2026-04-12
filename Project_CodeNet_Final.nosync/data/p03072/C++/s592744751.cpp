#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <set>
const int inf = 0x3f3f3f3f;
typedef long long ll;
const ll INF_LL  = 1e18;
using namespace std;
int mou[25],maxn[25];
int main(){
	ios::sync_with_stdio(false);
int n,cnt=1;
cin>>n;
for(int i=0;i<n;i++){
	cin>>mou[i];
		maxn[i]=max(mou[i],maxn[i-1]);
	}
for(int i=1;i<n;i++){
	if(mou[i]>=maxn[i])cnt++;
}
cout<<cnt;
return 0;
}
