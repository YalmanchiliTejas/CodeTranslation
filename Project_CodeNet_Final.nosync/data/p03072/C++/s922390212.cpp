#include <stdio.h>
#include <algorithm>
using namespace std;
int a[30];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a+i);
	int cnt= 1;
	int mx = a[0];
	for(int i = 1 ; i < n; i++){
		if(a[i] >= mx){
			cnt++;
			mx = a[i];
		}
	}
	printf("%d\n", cnt);
}