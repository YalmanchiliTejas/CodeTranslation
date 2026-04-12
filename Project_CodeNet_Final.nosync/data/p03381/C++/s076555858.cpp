#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

int n, a[MAXN], b[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	for(int i=0; i<n; i++){
		if(a[i] <= b[n / 2 - 1]) printf("%d\n", b[n / 2]);
		else printf("%d\n", b[n / 2 - 1]);
	}
}
