//
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <functional>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;


int main(){

  string str;
	cin >> str;
	if(str == "a" || str == "i" ||str == "u" ||str == "e" ||str == "o"){
		printf("vowel\n");
	}
	else printf("consonant\n");
	return 0;
}
