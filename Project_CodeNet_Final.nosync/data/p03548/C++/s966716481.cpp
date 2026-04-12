#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <sys/timeb.h>
#include <cstdio>
#include <sys/time.h>

using namespace std;
#define ll long long
#define uint unsigned int
#define ulong unsigned long long int

int main(){
	
	ll X,Y,Z;
	cin >> X >> Y >> Z;
	
	ll ma = 0;
	for(int i=1;i<X;i++){
		ll tot = i * Y + (i + 1) * Z;
		if(X >= tot) ma = i;
	}
	
	cout << ma << endl;
	
	
	
    return 0;
}