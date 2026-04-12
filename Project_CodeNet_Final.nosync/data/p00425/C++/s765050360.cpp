#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;

int main(){


	while(1){
	int n;
	cin >> n;
	if(n == 0)
		break;
	int over = 1;
	int under = 6;
	int forward = 2;
	int back = 5;
	int left = 4;
	int right = 3;

	int cnt = 0;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		if(str == "North"){
			int tmp = back;
			back = over;
			over = forward;
			forward = under;
			under = tmp;
		}
		else if(str == "East"){
			int tmp = over;
			over = left;
			left = under;
			under = right;
			right = tmp;
		}
		else if(str == "South"){
			int tmp = back;
			back = under;
			under = forward;
			forward = over;
			over = tmp;
		}
		else if(str == "West"){
			int tmp = over;
			over = right;
			right = under;
			under = left;
			left = tmp;
		}
		else if(str == "Right"){
			int tmp = back;
			back = left;
			left = forward;
			forward = right;
			right = tmp;
		}
		else if(str == "Left"){
			int tmp = back;
			back = right;
			right = forward;
			forward = left;
			left = tmp;
		}
		cnt += over;
	}

	cout << cnt+1 << endl;
	}

	return 0;
}