#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <sstream>
#define int_inf 1000000000 //1e9
#define ll_inf  1000000000000000000 //1e18
using namespace std;
template <typename T> std::string to_string(const T& t){
	std::ostringstream os; os<<t; return os.str();
}

int main(){
	int n;
	cin>>n;
	int x=n,y=0;
	y+=n/15;
	cout<<x*800-y*200<<endl;
	return 0;
}


