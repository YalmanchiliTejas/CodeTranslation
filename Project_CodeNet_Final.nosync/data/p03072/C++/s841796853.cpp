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
#define  rrep(i,n) for(int i=n;i>0;i--)
#define  REP(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
typedef vector<lld> vl;
typedef vector<int> vi;
typedef vector<string> vs;



//int arr[N]
////sort(arr,arr +N)

//vector <int> hoge
////sort(hoge.begin(),hoge.end());
///min_element(hoge.begin(),hoge.end();　最小値　　　最大値はmax_element();

int main() {

	int a,count=0,flag=0;
	vi x(100,0);
	cin>>a;
	rep(i,a){
		cin>>x[i];
	}
	rep(i,a){
		REP(m,0,i) {
			if (x[i] - x[m] < 0)
				flag=1;

		}
		if(flag==0)
			count++;
		flag=0;
	}
	cout<<count;
	return 0;
}

