#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
	int n;
	vector<int> v;	
	cin >> n;
	int sub;
	rep(i,n){
		cin >> sub;
		v.push_back(sub);
	}
	int k;
	for(int i=n-1;i>=0;i-=2){
		if(i!=n-1) cout << " ";
		cout << v[i];
	}
	if (n%2) k = 1;
	else k = 0;
	for(int i=k;i<n;i+=2){
		cout << " " << v[i];
	}

	cout << endl;
	return 0;
}
