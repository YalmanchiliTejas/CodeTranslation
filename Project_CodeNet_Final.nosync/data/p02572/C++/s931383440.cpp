#include <stdio.h>
#include <string.h>

int main(){
int a;
long long int sum = 0, x = 0;
long long int arr[200005];
scanf("%d", &a);
for(int i = 0; i < a;i++){
	scanf("%lld", &arr[i]);
}
for(int j = 0;j < a;j++){
	sum = (sum + x * arr[j]) % 1000000007;
	x = (x + arr[j]) % 1000000007;
}
printf("%lld", sum);
return 0;
}