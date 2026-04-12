#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdlib>
#include<cstdio>
#include<utility>
#include<list>
using namespace std;
int solve(int x, int y, int z){
	int i=0,res=0;
	while(res <= x){
		i++;
		res = y*i + z*(i+1);
	}

	return i-1;
}

int main(){
	int x,y,z; cin>>x>>y>>z;

	cout<< solve(x, y, z) <<endl;

	return 0;
}
