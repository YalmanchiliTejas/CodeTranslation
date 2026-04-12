#include <bits/stdc++.h>
using namespace std;

char s[100];
int  a,b;

int main(){
	cin>>s+1;
	for(int i = 1; i <= 3; i++){
		if(s[i] == 'A') a++;
		else b++;
	}
	if(a == 3 || b == 3) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}