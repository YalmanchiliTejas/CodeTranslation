#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	int t = 100*n+10*a+b;
	if(t%4 == 0)
		printf("YES\n");
	else
		printf("NO\n");
}
