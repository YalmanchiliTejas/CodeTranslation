#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;


int main(void){
	string a;
	cin >> a;
	int b =0 ,c =0;
	for(int e=0;e<a.size();e++){
		if(a[e]=='A') b++;
		else c++;
	}
	if(b==3||c==3) printf("No");
	else printf("Yes");
	return 0;
}
