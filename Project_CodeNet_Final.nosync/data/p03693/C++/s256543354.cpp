#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#define RG register

using namespace std;

inline int gi(){
	RG char ch=getchar();RG int x=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if ((a*100+b*10+c)%4==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
