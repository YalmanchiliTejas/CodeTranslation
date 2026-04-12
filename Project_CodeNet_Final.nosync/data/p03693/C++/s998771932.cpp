#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("readin.txt","r",stdin);
	int r,g,b;
	cin >> r >> g >> b;
	int ans = r*100 + g*10 + b;
	if(ans%4)
		puts("NO");
	else
		puts("YES");
}