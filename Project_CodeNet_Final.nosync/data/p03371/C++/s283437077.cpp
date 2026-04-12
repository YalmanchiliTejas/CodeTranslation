#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, c, x, y, pom, cena1=0, cena2=0, cena3=0;
	cin >> a >> b >> c >> x >> y;

	cena2 += x*a + y*b;

	pom = min(x,y);

	x-=pom;
	y-=pom;

	cena1 += c*pom*2;
	cena3 += c*pom*2;
	cena3 += c*y*2;
	cena3 += c*x*2;
	cena1 += b*y;
	cena1 += a*x;


	if(cena1 <= cena2 && cena1 <= cena3){
		cout << cena1 <<endl;
		return 0;
	}

	else if(cena2 <= cena3 && cena2 <= cena1){
		cout << cena2 <<endl;
		return 0;
	}

	cout << cena3 <<endl;

    return 0;
}
