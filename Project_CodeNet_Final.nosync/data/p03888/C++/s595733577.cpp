#include<map>
#include<set>
#include<cmath>
#include<regex>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>

#pragma warning(disable:4996)
using namespace std;

int main() {
	double r1, r2;
	scanf("%lf%lf",&r1,&r2);
	printf("%.12f\n",r1*r2/(r1+r2));
	return 0;
}