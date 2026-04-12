#include<bits/stdc++.h>
 
#define INF 1000000007
#define LINF 1000000000000000007
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;


char c;

int main(){
	cin >> c;
	
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel" << endl;
	else cout << "consonant" << endl;
	
	return 0;
}