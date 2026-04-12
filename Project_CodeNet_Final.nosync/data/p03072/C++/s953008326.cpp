#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100];
int main(){
	int N;
	scanf("%d",&N);
	int ans = 0; 
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
		bool flag = true;
		for(int j = 1;j < i;j++){
			if(a[j] > a[i]){
				flag = false;
				break;
			}
		}
		ans += flag;
	} 
	printf("%d\n",ans);
	return 0;
} 