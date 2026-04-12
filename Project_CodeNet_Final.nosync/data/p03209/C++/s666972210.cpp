#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define VOLUME_PRE_LEVEL ((long long)pow(2.0, (double)(level + 1)) - 3)
#define PUTTY_PRE_LEVEL ((long long)pow(2.0, (double)level) - 1)

int n;
long long x;

void input() {
	cin >> n >> x;
}

long long puttyInBurger(int level, long long bottom){
    if(level == 0) return 1;
    if(bottom <= 1) return 0;
    if(bottom <= 1 + VOLUME_PRE_LEVEL) return puttyInBurger(level - 1, bottom - 1);
    if(bottom <= 1 + VOLUME_PRE_LEVEL + 1) return PUTTY_PRE_LEVEL + 1;
    if(bottom <= 1 + (2 * VOLUME_PRE_LEVEL)) return PUTTY_PRE_LEVEL + 1 + puttyInBurger(level - 1, bottom - 1 - VOLUME_PRE_LEVEL - 1);
    return 2 * PUTTY_PRE_LEVEL + 1;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	input();
	
	cout << puttyInBurger(n, x) << "\n";
 
	return 0;
}
