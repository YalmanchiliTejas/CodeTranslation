#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include<functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

#define LL long long
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<LL>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<LL>
#define vecpii vector<pii>
#define vecpLL vector<pLL>
#define vecbL vector<bool>
#define endl "\n"
#define REP(e,v) for(auto e:v)
#define rep(i, a, n) for(LL i = a; i < n;i++)

using namespace std;

int inp(){
	int x;
	scanf("%d",&x);
	return x;
}
LL linp(){
	LL x;
	scanf("%lld",&x);
	return x;
}

void outp(int i){
	printf("%d",i);
}

void loutp(LL i){
	printf("%lld",i);
}

LL mod(LL i){
	return i % 1000000007;
}


int gcd(int i,int j){
	if(j != 0)
		return gcd(j, i % j);
	else
		return i;

}

int SaB(){

	string s;

	cin >> s;

	if(s.find("A") != -1 && s.find("B") != -1)
		printf("Yes");
	else
		printf("No");

	return 0;

}

signed main() {

	 SaB();
	return 0;
}