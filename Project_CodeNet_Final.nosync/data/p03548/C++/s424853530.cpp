#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <map>
#include <set>
using namespace std;
const long INF = 1000000009;

int x, y, z;
int main(){
	scanf("%d%d%d", &x, &y, &z);
	printf("%d\n", (x-z)/(y+z));
	return 0;
}