#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <string.h>

using namespace std;
#define  rep(i,n) for(int i=0;i<n;i++)
#define  REP(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
typedef vector<lld> vl;
typedef vector<int> vi;
typedef vector<string> vs;



//int arr[N]
////sort(arr,arr +N)

//vector <int> hoge
////sort(hoge.begin(),hoge.end());

int main() {
	int h,w,tmp=0;

	string ans;
	cin>>h>>w;
	vi flag_x(h,0),flag_y(w,0);
	vs a(h);
	rep(i,h){
			cin>>a[i];
	}

	rep(i,h){
		tmp=0;
		rep(k,w) {
			if (a[i][k] == '.')
				tmp++;
		}
		if(tmp==w){
			flag_x[i]=1;
		}

	}
	rep(i,w){
		tmp=0;
		rep(k,h) {
			if (a[k][i] == '.')
				tmp++;
		}
		if(tmp==h){
			flag_y[i]=1;
		}
	}

	rep(i,h){
		rep(k,w) {
			if(flag_x[i]!=1 &&flag_y[k]!=1 ){
				cout<<a[i][k];
			}

		}
		if(flag_x[i]!=1)
			cout<<"\n";
	}


	return 0;


}
