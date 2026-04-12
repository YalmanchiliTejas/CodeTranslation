//q055.cpp
//Tue Aug 25 22:09:54 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n];
	rep(i,n) cin >> a[i];

	multiset<int> ms;
	rep(i,n){
		auto itr = ms.lower_bound(a[i]);
		if(itr != ms.begin()){
			itr--;
			ms.erase(itr);
		}
		ms.insert(a[i]);
	}

	cout << ms.size() << endl;
//	printf("%.4f\n",ans);
}