//ΔATCODER QUALC A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int main()
{
	char ch[11];
	int i;
	cin>>ch;
	for(i=0;i<strlen(ch)-1;i=i+1)
		if(ch[i]=='A'&&ch[i+1]=='C'){
			cout<<"Yes\n";
			return 0;
		}
	cout<<"No\n";
	return 0;
}