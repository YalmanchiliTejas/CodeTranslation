
#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include<vector>
#include<cmath>

using namespace std;
typedef pair<int, int> P;
const int INF = 100000000;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



int main()
{
	int i,j,k,l,m,n,A,B,C,Y,flag,N,M,X,H, W;
	k = 0;
	long long int sum = 0;
	cin >>A>>B>>C>>X>>Y;
	if (2 * C <= A + B) {
		if (2 * C > A && 2 * C > B) {
			if (X > Y) {
			 sum=Y * 2 * C + A * (X - Y);
			}
			else {
				sum= X * 2 * C + B * (Y - X);
			}
		}
		else if (2 * C <= A&&2*C>B) {
			if (X > Y) {
				sum= X * 2 * C ;
			}
			else {
				sum= X * 2 * C + B * (Y - X) ;
			}
		}
		else if (2 * C <= B&&2*C>A) {
			if (X > Y) {
				sum=Y * 2 * C + A * (X - Y);
			}
			else {
				sum=Y * 2 * C;
			}
		}
		else {
			sum=fmax(X, Y)*C * 2;
		}

	}
	else {
		sum=A * X + B * Y;
	}


	flag = 0;
	cout << sum << endl;
	return 0;
}

