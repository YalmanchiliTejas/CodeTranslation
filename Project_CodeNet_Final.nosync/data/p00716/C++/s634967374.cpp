#include <iostream>

using namespace std;

int solve(int a, int year, int t, double r, int q)
{
	int b, x;
	int y = 0;
	if(t == 1){
		while(year--){
			b = a * r;
			x = a + b - q;
			a = x;
		}
	}
	
	if(t == 0){
		while(year--){
			b = a * r;
			x = a - q;
			y += b;
			a = x;
		}
	}
	return x + y;
}
	
void max(int n, int d[110])
{
	int z = 0;
	for(int i = 0; i < n; i++){
		if(z < d[i]) z = d[i];
	}
	cout << z << endl;
}

int main()
{
	int m;
	int a, year, n, t, q;
	double r;
	int d[110];
	
	cin >> m;
	while(m--){
		cin >> a;
		cin >> year;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> t >> r >> q;
			d[i] = solve(a, year, t, r, q);
		}
		max(n, d);
	}
	return 0;
}