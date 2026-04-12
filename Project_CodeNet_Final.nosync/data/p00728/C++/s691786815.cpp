#include <cstdio>
#include <algorithm>
using namespace std;

int s[100];

int main(){
	int n;
	while(scanf("%d", &n),n){
		for(int i = 0; i < n; i++) scanf("%d", &s[i]);
		sort(s,s+n);
		int sum = 0;
		for(int i = 1; i < n-1; i++){
			sum += s[i];
		}
		printf("%d\n", sum/(n-2));
	}
}