#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000
#define f(a, b) for (int i = a; i < b; i++)
#define f0(a) for (int i=0;i<a;i++)
#define input(d) cin >> d;
#define inputs(n,d) for(int i=0;i<n;i++){cin >> d[i];}
#define output(d) cout << d << endl;
#define outputs(n,d) for(int i=0;i<n;i++){cout << d[i] << endl;}

int main(void) {
	int n;
	input(n);
	if (n >= 30) {
		output("Yes")
	}
	else {
		output("No")
	}
	return 0;
}