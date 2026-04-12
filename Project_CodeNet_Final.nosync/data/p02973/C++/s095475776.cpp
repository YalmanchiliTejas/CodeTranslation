#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<map> 
#include<list>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#define ll long long
#define memset(a,n) memset(a,n,sizeof(a))
#define mp make_pair 
#define pb push_back
using namespace std;
const int maxn = 1e6 + 100;


int main()
{
	int n;cin >> n;deque<int> q;
	for(int i = 1; i <= n;i++){
		int x;cin >> x;
		int it = lower_bound(q.begin(),q.end(),x) - q.begin();
		if(!it){
			q.push_front(x);
		}else{
			q[it - 1] = x;
		}
	}
	printf("%d\n",q.size());
}
