//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
using namespace std;
 
int N,M;

string ans;
 
void solve(){
	if(N==M){
		ans = "Yes";
		return;
	}
	ans = "No";
}
 
int main(){
	cin>>N>>M;

	solve();

	cout<<ans;
	return 0;
}