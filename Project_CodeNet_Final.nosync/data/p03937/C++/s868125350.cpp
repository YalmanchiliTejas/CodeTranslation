#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int H,W;
string S[8];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	cin >> H >> W;
	for(int i=0; i<H; i++) cin >> S[i];
	bool checked[8][8] = {};
	int y = 0; int x = 0;
	checked[y][x] = true;
	while(y != H-1 || x != W-1){
		int c = 0;
		if(y < H-1 && S[y+1][x] == '#') c++;
		if(x < W-1 && S[y][x+1] == '#') c++;
		if(c != 1){
			cout << "Impossible" << endl;
			return 0;
		}
		if(y < H-1 && S[y+1][x] == '#') y++;
		else x++;
		checked[y][x] = true;
	}
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if((checked[i][j]&&S[i][j]=='#') || (!checked[i][j]&&S[i][j]=='.')){
			}
			else{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;

	return 0;
}