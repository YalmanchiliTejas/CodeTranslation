#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int SURP = 1000000007;

int main(){
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;

	int m = max(X,Y) * 2;
	long long int min = 1000000000000;
	FOR(i,0,m+1){
		if(i%2 == 0){
			long long int cash = 0;
			cash = i * C + A * max((X- i/2),0) + B * max((Y- i/2),0);
			if (min > cash) min = cash;
		}
	}

	cout << min << endl;
	return 0;


}