
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
	
	int n, a, b, c, x;
	cin>> n>> a>> b>> c>> x;
	if(n==0 && a==0 && b==0 && c==0 && x==0) return false;
	vector<int> y(n);
	for(int i=0;i<n;i++){
		int in;
		cin>> in;
		y[i] = in;
	}

	int cnt = 0;
	int flag = 0;
	int ans;
	for(int i=0;i<10001;i++){			//10001だった
		if(y[cnt] == x) cnt++;
		if(cnt==n){
			ans = i;
			flag++;
			break;
		}
		x = (a * x + b) % c;
	}
	
	if(flag){
		cout<< ans<< endl;
	}else{
		cout<< -1<< endl;
	}
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	while(solve());

	return 0;
}

 