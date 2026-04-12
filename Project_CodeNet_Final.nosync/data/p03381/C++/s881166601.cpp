#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

int n;

std::vector<int> x;
std::vector<int> v;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		x.push_back(a);
	}
	v = x;
	std::sort(v.begin(), v.end());
	int med1, med2;
	med1 = v[n/2-1];
	med2 = v[n/2];
	for(int i = 0; i < n; i++){
		if(x[i] < med2){
			printf("%d\n", med2);
		}else{
			printf("%d\n", med1);
		}
	}
	return 0;
}
