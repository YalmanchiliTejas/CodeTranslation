
#include<bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
const int N = 5;
const int mod = 1e9 + 7;
int mul(int a, int b) {return 1LL * a * b % mod;}
int add(int a, int b){
	a += b;
	if(a > mod) a -= mod;
	return a;
}

int main(){
	int n, sum = 0, ans = 0;
	scanf("%d", &n);	
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		ans = add(ans, mul(sum, x));
		sum = add(sum, x);
	}
	printf("%d", ans);

}