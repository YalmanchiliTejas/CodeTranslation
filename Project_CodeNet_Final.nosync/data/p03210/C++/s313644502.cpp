#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
string s;
int mutu(int a){
	int b=1;
	for(int i=a+1;i!=s.size();i++){
		if(s[i]==s[a]) b++;
		else break;
	}
	return b;
}
int solve(int a){
	int i=a;
	for(;i!=s.size();i++){
		if(s[i]=='J') break;
	}
	return i-1;
}
int mypow(int a,int b,int c){
	if(b==1) return a%c;
	if(b%2) return a*mypow(a,b-1,c)%c;
	int d=mypow(a,b/2,c);
	return d*d%c;
}
signed main(){
	int a;
	cin>>a;
	if(a==3||a==5||a==7) puts("YES");
	else puts("NO");
	return 0;
}
