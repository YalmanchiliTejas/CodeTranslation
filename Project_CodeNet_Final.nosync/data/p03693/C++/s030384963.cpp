#include<bits/stdc++.h>
#define clr(x, y) memset(x, y, sizeof(x))
#define fl(a, b) for(int i=a; i<b; i++)
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const int inf = INT_MAX;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int s = a*100 + 10*b + c;
	if(s%4==0) puts("YES");
	else puts("NO");
}