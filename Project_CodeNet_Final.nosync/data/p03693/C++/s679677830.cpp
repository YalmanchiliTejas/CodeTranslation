#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	r=r*100+g*10+b;
	printf("%s\n",r%4==0?"YES":"NO");
	return 0;
}
