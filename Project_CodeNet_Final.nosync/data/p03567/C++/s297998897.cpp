#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
char a[100];
int main()
{
	cin>>a+1;
	int n = strlen(a+1);
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 'A' && a[i+1] == 'C') flag = 1;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}