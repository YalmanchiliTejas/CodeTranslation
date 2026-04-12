#include<algorithm>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <string.h>
using namespace std;
int main(void){
	int x,y,z,ans;
	cin>>x>>y>>z;
	ans=(x-z)/(y+z);
	cout<<ans<<endl;
	return 0;
}
