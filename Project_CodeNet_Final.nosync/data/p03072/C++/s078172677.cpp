#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n0,n) for(int i=n0;i<n;i++)
#define Com(i,j,n) for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)
const int INF =100100100;
const int MOD = (int)1e9+7;
const double EPS = 1e-9;
typedef long long ll;
typedef long li;
#define pb push_back 
#define mp make_pair



signed main (){	
	int NN,max,hh,count=0;
	cin >> NN ;
	rep(i,NN) {
		cin >> hh ;
		if(i==0){
			count += 1;
			max = hh;
		} else {
			if(hh >= max) {
				count += 1;
				max = hh;
			}
		}
	}
	cout << count << endl;
}
