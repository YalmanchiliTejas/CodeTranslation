#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;cin>>n;
	char s[19];cin>>s+1;
	cin>>k;
	for(int i=1;s[i];++i)
		printf(s[i]==s[k] ? "%c" :  "*"  ,s[k]);
	return 0;
}
