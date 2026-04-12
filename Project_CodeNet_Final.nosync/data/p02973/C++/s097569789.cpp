#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 100009
#define LL long long
#define INF 0x3f3f3f3f
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
int A[N], mark[N], mxt1[N];
multiset<int> mst;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	multiset<int>::iterator iter;
	for(int i = n; i > 0; i--){
		if((iter = mst.upper_bound(A[i])) != mst.end()){
			mst.erase(iter);
		}
		mst.insert(A[i]);
	}
	cout << mst.size() << endl;
	return 0;
}
