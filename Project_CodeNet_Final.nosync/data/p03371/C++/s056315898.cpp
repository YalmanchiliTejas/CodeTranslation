#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int min=1e9;
	for(int i=0; i<=2*x || i<=2*y; i+=2){
		int pa=max(0, x-i/2), pb=max(0, y-i/2);
		int cost=i*c+pa*a+pb*b;
		if(min>cost) min=cost;
	}
	cout << min<< endl;		
	return 0;
}