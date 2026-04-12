#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;


int main(){
	int n;
	cin >> n;
	int a[10000];
	for(int i=0;i<n;i++) cin >> a[i];

	int ans = 0;
	for(int i=0;i<n;i++){
		bool ok = true;
		for(int j=i;j>=0;j--){
			if(a[i]<a[j]) ok = false;
		}
		if(ok) ans++;
	}
	cout << ans << endl;

	return 0;
}