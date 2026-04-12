#include <bits/stdc++.h>
using namespace std;

main(){
	int x,y,z;
	cin >> x >> y >> z;
	int a = x / y;
	int i;
	for(i=a; i>=0 && x-(y*i) < z*(i+1); --i);
	printf("%d\n", i);
}
