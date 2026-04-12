#include<iostream>
using namespace std;
typedef long long int ll;
int main(){
	ll K, A, B;
	cin >> K >> A >> B;
	if(A >= K) cout << 1 << endl;
	else if(B >= A) cout << -1 << endl;
	else if((K - A) % (B - A) == 0) cout << 1 + (K - A) / (A - B) * 2 << endl;
	else cout << 1 + ((K - A) / (A - B) + 1) * 2 << endl;
	return 0;
}