#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())

int n;
int a[200000];
int b[200000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i, n)cin >> a[i];
	int h=0,t=n-1;
	for (int i=n-1;i>=0;i--){
		if ((n-i)&1){
			b[h++] = a[i];
		}
		else{
			b[t--] = a[i];
		}
	}
	cout << b[0];
	rep(i,n-1){
		cout << ' ' << b[i+1];
	}
	cout<<endl;
	return 0;
}