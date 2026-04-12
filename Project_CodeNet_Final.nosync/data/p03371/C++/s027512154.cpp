#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;



int main(){
	int a,b,c,x,y;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

	long long min = 5000*100000*2;
	for(int i=0;i<=100000;i++){
		long long tmp = i*2*c + max(0,x-i)*a + max(0,y-i)*b;
		if(min > tmp) min = tmp;
	}

	printf("%lld\n", min);

	return 0;
}
