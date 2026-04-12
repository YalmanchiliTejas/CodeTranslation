//abc049_a.cpp
//Fri Oct 19 22:45:44 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	char s;
	cin >> s;

	if (s == 'a' || s == 'i' ||s == 'u' ||s == 'e' ||s == 'o'){
		cout << "vowel" << endl;
	}else {
		cout << "consonant" << endl;
	}
}