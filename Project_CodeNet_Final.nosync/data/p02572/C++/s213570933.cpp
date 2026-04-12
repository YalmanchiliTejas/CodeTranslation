#include <bits/stdc++.h>
using namespace std;
void check()
{
    if(false)
    cout<<"C"<<endl;
}
#define ll long long
int main() {
    long long n,i,z,t;
    long long aa,bb,cc;
cin >> n;
	ll vious[n + 1], a[n + 1];
	memset(vious, 0, sizeof(vious));
	memset(a, 0, sizeof(a));
check();
	for(i=1; i<n + 1; i+=1) {
		cin >> a[i];
		vious[i] = ( vious[i - 1] + a[i]) % 1000000007;
	}
check();
	z = 0;
check();
	for(i= 2;i<n + 1; i+=1) {
		t = (vious[i - 1] * a[i]) % 1000000007;
		z =z+ t;
		z = z % 1000000007;
	}

	cout<<z<<"\n";
}