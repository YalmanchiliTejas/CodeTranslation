#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;

int main()
{
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	int sum = 0;
	if( A + B > (2*C)){
		int Z = min(X,Y);
		sum += 2*Z*C;
		X -= Z;
		Y -= Z;
	}
	if( A > 2*C){
		sum += 2*X*C;
		X = 0;
		Y = max(0,Y-X);
	}
	if( B > 2*C){
		sum += 2*Y*C;
		Y = 0;
		X = max(0,X-Y);
	}
	sum += A*X + B*Y;
	cout<<sum<<endl;
	return 0;
}

