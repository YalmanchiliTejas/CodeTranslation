#include "bits/stdc++.h"

using namespace std;
		int store = 0;
		int s[10];
		int a[5];
		int ma = 0;
		bool unko = 0;

int main (){
	
	while(1){
		ma = 0;
		unko = 0;
		store = 0;
		int i;
	for(int k = 0;k <= 4;k++){
		i = 2 * k;
	cin >> s[i] >>s[i + 1];
	if(s[i] == 0 && s[i + 1] == 0) 
		{unko = 1; 
	break;
	}
	a[k] = (s[i] + s[i + 1]);
	if(ma < a[k]) {
		store = k;
		ma = a[k];
	}
	}
	if(unko == 1)break;
	switch(store){
	case 0:
		cout << "A " << ma <<endl;
		break;

	case 1:
		cout << "B " << ma <<endl;
		break;

	case 2:
		cout << "C " << ma <<endl;
		break;

	case 3:
		cout << "D " << ma <<endl;
		break;

	case 4:
		cout << "E " << ma <<endl;
		break;
	}



	}

	return 0;
}