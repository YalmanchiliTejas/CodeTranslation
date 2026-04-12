#include <bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define debug(var) std::cout << #var << " : " << var << std::endl;
using ll = long long;
using ull = unsigned long long;
ll mod = 1e9 + 7;

int main(){


	char c; std::cin >> c;
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')std::cout << "vowel";
	else std::cout << "consonant";

	
	return 0;
}