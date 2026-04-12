#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int calc(int f, int y, int c, double r, int t)
{
	int m = f;
	int a=0;

	if(t==0){
		for(int i=0; i<y; i++){
			a = a + (int)(m * r);
			m = m - c;
		}
	}
	else{
		for(int i=0; i<y; i++){
			m = m + (int)(m * r) - c;
		}
	}

	return (m+a);
}

int main()
{
	int m, f, y, n, t, c, max, a;
	double r;

	cin >> m;
	for(int i=0; i<m; i++){
		cin >> f >> y >> n;
		max=0;
		for(int j=0; j<n; j++){
			cin >> t >> r >> c;
			a = calc(f,y,c,r,t);
			if(max<a){max=a;}
		}
		cout << max << endl;
	}

	return 0;
}