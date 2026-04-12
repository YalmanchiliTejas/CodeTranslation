#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	x-=z,y+=z;
	cout<<x/y<<endl;
	return 0;
}