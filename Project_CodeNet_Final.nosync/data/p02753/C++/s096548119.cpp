#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<3;++i){
		if(s[i]=='A') ++num;
	}
	if(num==1||num==2) printf("Yes");
	else printf("No");
	return 0;
}