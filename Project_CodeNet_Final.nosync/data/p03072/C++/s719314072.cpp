#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	int n,ma=-1,cnt=0;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v.at(i);
		if(v.at(i)>=ma)cnt++;
		ma=max(ma,v.at(i));
	}
	cout<<cnt<<endl;

	return 0;
}

