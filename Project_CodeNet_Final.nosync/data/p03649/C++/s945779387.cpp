#include<iostream>
using namespace std;
int n;
long long int a[55];
int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	long long int res = 0;
	while(true){
		int p = -1;
		for(int i=0; i<n; i++)
			if(p == -1 || a[i] > a[p])
				p = i;
		if(a[p] >= n){
			long long int w = a[p] / n;
			a[p] -= w*n;
			for(int j=0; j<n; j++)if(j!=p)
				a[j] += w;
			res += w;

		}else
			break;
	}
	cout << res << endl;
	return 0;
}
