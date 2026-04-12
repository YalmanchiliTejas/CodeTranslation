#include <iostream>

#include<math.h>

#include<stdio.h>

#include<string.h>

#include<vector>

#include<algorithm>



typedef long long lli;

#define rep0(i, n) for(int i=0; i < (int)(n); i++)

#define rep1(i, n) for(int i=1; i < (int)(n); i++)

#define all(x) (x).begin(),(x).end()

#define fill(x,y) memset(x,y,sizeof(x))

#define debug1(i) cout << i << '\n'

#define debug2(i,j) cout << i << j << '\n'



using namespace std;



int main() {
	lli a[20], b, c, n;
	cin >> n;
	vector<lli> vec(n, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (vec[i] >= vec[j])k++;
		}
		if (k == i)ans++;
	}
	cout << ans;
	
}