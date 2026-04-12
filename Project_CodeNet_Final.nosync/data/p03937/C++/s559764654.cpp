#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>

#include <vector>
#include <queue>

#include <utility>
#include <map>

// #include <bits/stdc++.h>

#define LL long long
#define vi vector<int>
#define set0(x) memset((x),0,sizeof((x)))
#define set1(x) memset((x),1,sizeof((x)))
#define setmin(x) memset((x),-1,sizeof((x)))
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

#define MOD 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int h,w;
	int max1=1,min1=1,max2=1,min2=1;
	bool check=1;
	bool found=0;
	char x[10][10];
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>x[i][j];
		}
	}
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(i%2==1){
				if(x[i][j]=='#') {
					if(!found){
					min1=j;
					found=1;
					}  else max1=j;
				}
			} else {
				if(x[i][j]=='#') {
					if(!found){
					min2=j;
					found=1;
					}  else max2=j;
				}
			}	
		}
		if(max1<min1) max1=min1;
		if(max2<min2) max2=min2;
		found=0;
		if(i%2==0){
			if(max1==min2) continue; else {
			check=0;
			break;
			}
		} else {
			if(max2==min1) continue; else {
			check=0;
			break;
			}
		}

//		cout<<min1<<" "<<max1<<" "<<min2<<" "<<max2<<endl;
	}
	
	if(check) cout<<"Possible"<<endl; else cout<<"Impossible"<<endl;
	return 0;
}
/*
##... m0 = min row m1 max row m2 min row berikut
.###.
.###.
...##
*/