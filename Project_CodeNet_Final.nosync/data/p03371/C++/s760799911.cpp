#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, C, Xa, Yb;
	int nA = 0, nB = 0;
	cin >> A >> B >> C >> Xa >> Yb;
	int custo = 0;
	if (C*2<A+B)
	{
		int amais;
		int amenos;
		amais = (max(Xa, Yb))*2*C;
		if (Xa>Yb)
		{
		amenos = ((min(Xa, Yb))*2*C)+(Xa-Yb)*A;
		} else {
		amenos = ((min(Xa, Yb))*2*C)+(Yb-Xa)*B;
		}
		custo+=min(amais, amenos);
	} else {
		custo+=Xa*A+Yb*B;
	}

	cout << custo;
	return 0;
}