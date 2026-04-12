#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> P;
const int c_INF = 111111111;
const int c_mINF = -111111111;
const int c_YET = -1;
const int c_Dx[4] = { 0,0,1,-1 };
const int c_Dy[4] = { 1,-1,0,0 };
const int c_div = 1000000007; //10^9 + 7



int main() {


	char S;
	scanf("%c", &S);

	if (S == 'a' || S == 'i' || S == 'u' || S == 'e' || S == 'o') {
		printf("vowel");
	}
	else {
		printf("consonant");
	}


}