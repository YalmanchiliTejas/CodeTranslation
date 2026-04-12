#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int a, b, c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	int ans = 100 * a + 10 * b + c;
	if(ans % 4 ==  0) printf("YES\n");
	else printf("NO\n");
}
