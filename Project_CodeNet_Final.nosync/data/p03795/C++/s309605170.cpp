#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m;
int ans;
int main(){
	while(~scanf("%d", &n)){
		ans = n * 800;
		m = n / 15;
		printf("%d\n", ans - ( m * 200));
	}
	return 0;
}
