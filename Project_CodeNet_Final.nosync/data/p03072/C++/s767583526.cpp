#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#define REP(i,a) for(int i = 0; i < (a); i++)
using namespace std;

int main(){
	int n;
	cin >> n;
	int h[n];
	REP(i,n)cin >> h[i];
	int res = 1,max = h[0];
	REP(i,n - 1){
		if(h[i + 1] >= max){
			max = h[i + 1];
			res++;
		}
	}
	cout << res << endl;
}