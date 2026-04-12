#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n = 0;
	for(int i = 1; i <= 3; i++){
		int a;
		scanf("%d", &a);
		n = n * 10 + a;
	}
	if(n % 4 == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
