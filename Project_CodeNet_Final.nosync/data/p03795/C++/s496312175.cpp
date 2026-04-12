#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
	int N;
	int work;
	cin >> N;
	work = N / 15;
	cout << (N * 800) - (work * 200) << endl;
	return 0;
}
