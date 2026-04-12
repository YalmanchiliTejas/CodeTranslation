#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, int> P;
#define MOD (1000000007ll)

ll sq(ll x){
	return x*x;
}

bool isvowel(char c){
	int i;
	string v="aeiou";
	for(i = (v.size()-1); i>=0; i--){
		if(c == v[i]){
			return true;
		}
	}
	return false;
}

int main(void){
	char c;
	cin >> c;
	cout << ((isvowel(c)?"vowel":"consonant")) << endl;
	return 0;
}