#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, q, a[100005];

void update(int x){
	if(x > 1) a[x-1] = 1;
	if(x < n) a[x+1] = 1;
}

int main(){
	scanf("%d %d",&n,&q);
	a[1] = 1; update(1);
	int cp = 1;
	while(q--){
		int aa, bb;
		scanf("%d %d",&aa,&bb);
		if(cp == aa) cp = bb;
		else if(cp == bb) cp = aa;
		swap(a[aa], a[bb]);
		update(cp);
	}
	cout << count(a + 1, a + n + 1, 1) << endl;
}
