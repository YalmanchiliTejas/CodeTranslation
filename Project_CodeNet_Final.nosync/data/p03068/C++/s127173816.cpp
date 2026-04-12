#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>
#include <bitset>
#include <map>
#include <limits.h>
using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> P;
const int INF = 1e9;

long long gcd(long long x, long long y){
			if(x<y){
				long long temp = x;
			x = y;
				y = temp;
			}
			long long r = x % y;
				while(r!=0){
					x = y;
					y = r;
				r = x % y;
	    		}
			return y;
	    }

int main(){
int N;
string S;
int K;
cin >> N;
cin >> S;
cin >> K;
char ans = S[K-1];
for(int i = 0; i< N;i++){
    if(ans!=S[i]){
        S[i] = '*';
    }
}
cout << S << endl;
}
