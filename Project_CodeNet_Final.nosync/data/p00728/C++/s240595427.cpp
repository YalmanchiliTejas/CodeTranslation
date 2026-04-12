#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int in,a,maxer=0,miner=1000;
	int sum=0;
	int i=0;
	double ave=0.0;
	while( cin >> in,in ){
		for(i=0; i<in; i++){
			cin >> a;
			maxer=max(a,maxer);
			miner=min(a,miner);
			sum += a;
		}
		sum = sum - maxer - miner;
		ave = sum/(in-2);
		cout << floor(ave) << endl;
		sum = maxer = ave = 0;
		miner=1000;
	}
}