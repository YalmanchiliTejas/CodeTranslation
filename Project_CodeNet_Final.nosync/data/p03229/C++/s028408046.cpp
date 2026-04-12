/*
 * a.cpp
 *
 *  Created on: 2019/06/08
 *      Author: MEIP-users
 */




#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <locale>
#include <queue>
#include <tuple>
#include <map>
#include <fstream>

using namespace std;


#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1e9+10)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))




int main() {
	int n;
	cin >> n;
	vector<ll> as(n);
	rep(i, n){
		ll a;
		cin >> a;
		as[i] = a;
	}
	sort(as.begin(),as.end());
	ll ans = 0;
	if(n%2 == 0){
		REP(i, n){
			if(i < n/2-1){
				ans -= 2*as[i];
			}else if(i > n/2){
				ans += 2*as[i];
			}else if(i == n/2){
				ans += as[i];
			}else{
				ans -= as[i];
			}
		}
	}else{
		REP(i, n){
			if(i < (n-1)/2-1){
				ans -= 2*as[i];
			}else if(i > (n-1)/2){
				ans += 2*as[i];
			}else if(i == (n-1)/2){
				ans -= as[i];
			}else{
				ans -= as[i];
			}

		}
		ll amp = ans;
		ans = 0;
		REP(i, n){
			if(i < (n+1)/2-1){
				ans -= 2*as[i];
			}else if(i > (n+1)/2){
				ans += 2*as[i];
			}else if(i == (n+1)/2){
				ans += as[i];
			}else{
				ans += as[i];
			}

		}
		ans = max(ans,amp);
	}
	cout << ans << endl;
	return 0;
}
