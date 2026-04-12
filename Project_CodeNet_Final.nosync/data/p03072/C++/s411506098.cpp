#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <ios> 
#include <iomanip>
using namespace std;

#define N_MAX   (100000)
#define LL_MAX_NUM (1LL<<60)
#define INF 1e7

typedef long long ll;
typedef long long int lli;

int main() {
	int N, res, max;
	cin >> N;
    res = 0;
    for (int i = 0; i < N; i++) {
        int Hi;
        cin >> Hi;
        if (i == 0) {
            max = Hi;
        }else {
            if (max <= Hi) {
                max = Hi;
                res++;
            }
        }
    }
	cout << res+1 << endl;
	return 0;
}