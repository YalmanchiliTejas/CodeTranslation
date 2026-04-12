#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
void print(int x){
	char y=x%10+'0';
	if(x>=10)print(x/10);
	putchar(y);
}
int n,x,ans;
multiset<int> s;
int main(){
	n=read();
	for(int i=0;i<n;i++){
		x=read();
		multiset<int>::iterator y=s.lower_bound(x);
		if(y==s.begin())ans++,s.insert(x);
		else y--,s.erase(y),s.insert(x);
	}
	print(ans);
	return 0;
}