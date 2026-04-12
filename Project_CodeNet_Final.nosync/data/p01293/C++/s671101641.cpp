#define _USE_MATH_DEFINES
#include <iostream>
#include <memory>
#include <memory.h>
#include <fstream>
#include <cmath>
#include <numeric>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <list>
#include <cctype>
#include <algorithm>
#include <complex>
using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef unsigned long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 29;
const double EPS = 1E-10;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)

string card[4][13];
int get_rank(char ch){
	if(isdigit(ch)){
		return ch - '0';
	}else if(ch == 'T'){
		return 10;
	}else if(ch == 'J'){
		return 11;
	}else if(ch == 'Q'){
		return 12;
	}else if(ch == 'K'){
		return 13;
	}else return 100;
}

int main(){
	char trump, led;
	while(cin >> trump && trump != '#'){
		int cntEW = 0, cntNS = 0;
		int leader = 0;
		rep(i, 4)rep(j, 13) cin >> card[i][j];

		rep(i, 13){
			bool f = false;
			int best = 0;
			int id = 0;
			led = card[leader][i][1];
			rep(j, 4) if(card[j][i][1] == trump) f = true;
			rep(j, 4){
				if(f){
					if(card[j][i][1] == trump && get_rank(card[j][i][0]) > best){
						best = get_rank(card[j][i][0]);
						id = j;
					}
				}else{
					if(card[j][i][1] == led && get_rank(card[j][i][0]) > best){
						best = get_rank(card[j][i][0]);
						id = j;
					}
				}
			}
			if(id % 2 == 0) cntNS++;
			else cntEW++;
			leader = id;
		}

		if(cntEW > cntNS){
			cout << "EW " << cntEW - 6 << endl;
		}else{
			cout << "NS " << cntNS - 6 << endl;
		}
	}
	return 0;
}