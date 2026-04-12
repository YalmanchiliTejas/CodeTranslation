#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

#define PQ priority_queue
#define P pair<int,int>
#define CLA(array) memset(array,0,sizeof array)
#define CLINF(array) memset(array,0x3f,sizeof array)
#define CLF(array) memset(array,-1,sizeof array)
#define DB(a) cout << "DEBUG " << a << endl;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100000 + 50;
const int INF = 1 << 30;
int k;
LL a[55];

bool ok(){
	for(int i = 0; i < k; i++){
		if(a[i] >= k) return false;
	}
	return true;
}
int main(){
    //ios_base::sync_with_stdio(false);
	while(~scanf("%d", &k)){
		LL sum = 0, sum2 = 0;
		for(int i = 0; i < k; i++){
			scanf("%lld", &a[i]);
			if(a[i] >= k) sum += (a[i] / k);
			sum2 += a[i];
			// cout << a[i] - k << endl;
		}
		sort(a, a+k);
		if(a[k-1] < k){
			printf("0\n");
			continue;
		}
		// cout << sum << endl;
		// cout << sum2 << endl;
		LL ans = 0;
		while(!ok()){
			for(int i = 0; i < k; i ++){
				LL tmp = a[i]/k;
				a[i] %= k;
				ans += tmp;
				for(int j = 0; j < k; j++){
					if(i!=j) a[j] += tmp;
				}
			}
		}
		cout << ans << endl;
		// cout << sum/(LL)k << endl;
	}


    return 0;
}
