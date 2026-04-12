#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll unsigned long long int
#define abs(N) (((N)>0)?(N):(-1)*(N))

using namespace std;

int n;

ll calc(int * a){
	ll sum=0;

	for (int i = 0; i < n-1; ++i) {
		int d = a[i+1]-a[i];
		sum += abs(d);
	}

	return sum;
}

int main() {
	cin >> n;

	int a[n],b[n],c[n];
	ll sb,sc,smax=0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a,a+n);

	for (int i = 0; i < n; ++i) {
		int j;
		if(i%2==0){
			j = n-1-i/2;
		}else{
			j = (i-1)/2;
		}
		b[i] = a[j];
		c[(i+1)%n]=a[j];
	}
	sb = calc(b);
	sc = calc(c);
	smax =  (sb>sc)?sb:sc;

	for (int i = 0; i < n; ++i) {
		int j;
		if(i%2==0){
			j = i/2;
		}else{
			j = n - 1 - (i-1)/2 ;
		}
		b[i] = a[j];
		c[(i+1)%n]=a[j];
	}
	sb = calc(b);
	sc = calc(c);
	if(sb>smax)smax = sb;
	if(sc>smax)smax = sc;


	cout << smax << endl;



	return 0;
}
