#include <bits/stdc++.h>
using namespace std;
int read(){
	int sum=0,f=1;
	char s=getchar();
	while (s<'0' or s>'9'){
		if (s=='-')f=-1;
		s=getchar();
	}
	while (s>='0' and s<='9'){
		sum=sum*10+s-'0';
		s=getchar();
	}
	return sum*f;
}
int n;
int main(){
	n=read();
	if (n>=30)cout<<"Yes"<<endl;
	else cout<<"No\n";
	
	return 0;
}

