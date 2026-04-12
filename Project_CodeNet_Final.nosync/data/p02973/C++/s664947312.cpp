#include<bits/stdc++.h>
using namespace std;
int n, a, b[100005];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		a++;
		*(lower_bound(b,b+n,a)-1) = a;
	}
	printf("%d\n",n-(lower_bound(b,b+n,1)-b));
}