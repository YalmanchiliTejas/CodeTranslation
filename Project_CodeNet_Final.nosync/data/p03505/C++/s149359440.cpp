#include <bits/stdc++.h>

using namespace std;

int main(){
	long long k,a,b;
	cin>>k>>a>>b;
	if(k<=a) {putchar('1');return 0;}
    else if(a<=b) {puts("-1");return 0;}
    else printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
	return 0;
}