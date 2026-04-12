#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int e[15];
	int i,cnt;
	for(i=0;i<12;i++) cin>>e[i];
	sort(e,e+12);
	cnt=0;
	for(i=1;i<4;i++){
		if(e[0]!=e[i]) break;
		cnt++;
	}
	for(i=5;i<8;i++){
		if(e[4]!=e[i]) break;
		cnt++;
	}
	for(i=9;i<12;i++){
		if(e[8]!=e[i]) break;
		cnt++;
	}
	if(cnt==9) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
