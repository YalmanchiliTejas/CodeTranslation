//====================================//
#include <bits/stdc++.h>
//====================================//

using namespace std;
#define ll long long 


//====== Data Structure =//

//=======================//

//====== Variables ======//
int a, b, c;
//=======================//

//====== Functions ======//

//=======================//

int main(int argc, char *argv[]) {
	
	//==========================//
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	//==========================//
	
	cin >> a >> b >> c;
	int comb = b * 10 + c;
	if (comb % 4 == 0)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}