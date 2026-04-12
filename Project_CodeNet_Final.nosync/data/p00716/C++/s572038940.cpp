
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;


bool solve(){
	long sisan;
	int n;
	int nen;
	cin>> sisan>> nen>> n;
	
	long ans = sisan;
	for(int i=0;i<n;i++){
		long s = sisan;
		int hukuri;
		double riritu;
		int tesuu;
		cin>> hukuri>> riritu>> tesuu;
		if(!hukuri){
			long risokuwa = 0;
			for(int j=0;j<nen;j++){
				risokuwa += s * riritu;
				s -= tesuu;
			}
			s += risokuwa;
		}else{
			for(int j=0;j<nen;j++){
				s *= (1+riritu);
				s -= tesuu;
			}
		}
		ans = max(ans, s);
	}
	cout<< ans<< endl;
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		solve();
	}
	
	return 0;
}

 