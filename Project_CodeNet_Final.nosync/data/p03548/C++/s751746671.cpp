// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int main() {
	scanf("%d%d%d",&x,&y,&z);
	x=x-z;
	cout<<x/(y+z)<<endl;
	return 0;
}