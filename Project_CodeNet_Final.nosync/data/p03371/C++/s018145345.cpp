#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define INF (1<<31-1)
#define ll long long

int A, B, C, X, Y;

ll calc(int a, int b, int c){
	return (ll)a*A + (ll)b*B + (ll)c*C;
}

int main(){

	long long cost = (ll)INF;

	cin >> A >> B >> C >> X >> Y;

	cost = min(cost, calc(X, Y, 0));
	cost = min(cost, calc(0, 0, 2*max(X,Y)));
	if (X>Y)
		cost = min(cost, calc(X-Y, 0, 2*Y));
	else
		cost = min(cost, calc(0, Y-X, 2 * X));


	cout << cost << endl;


	return 0;
}
