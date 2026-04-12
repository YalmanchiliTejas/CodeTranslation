#define _USE_MATH_DEFINES 
#include <iomanip> 
#include <cmath>  
#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl


int main() {
	char c;
	rd(c);
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')wrln("vowel");
	else wrln("consonant");

	return 0;
}