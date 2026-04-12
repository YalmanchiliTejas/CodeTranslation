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
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	int *h = new int[n];
	rep(i,n) cin>>h[i];
	ll ans = 0;
	for(int i = 0; i < n; i++){
		bool ok = true;
		for(int j = 0; j < i; j++){
			if( h[j] > h[i]){
				ok = false;
				break;
			}
		}
		if( ok == true) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

