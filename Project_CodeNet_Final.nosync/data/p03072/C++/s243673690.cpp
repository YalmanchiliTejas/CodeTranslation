#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ull)(1e9)+7)
#define MAX ((ull)(1e9)+1)

int main(){
	int n;
	cin >> n;
	int h[n], m[n], ans=0;
	for(int i=0; i<n; i++) cin >> h[i];
	m[0]=h[0];
	for(int i=1; i<n; i++) m[i]=max(m[i-1], h[i]);
	for(int i=0; i<n; i++){
		if(m[i]<=h[i]) ans++;
	}
	cout << ans << endl;
 	return 0;
}