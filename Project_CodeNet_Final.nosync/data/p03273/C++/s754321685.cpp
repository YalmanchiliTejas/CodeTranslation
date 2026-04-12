#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int h,w;
char mm[101][101];

int main(int argc,char** argv) {
	string s;
	cin >> h >> w;
	set<int> skipx,skipy;
	for(int y = 0;y < h;y++) {
		cin >> s;
		bool ad = true;
		for(int x = 0;x < w;x++) {
			mm[x][y] = s[x];
		}
	}
	for(int x = 0;x < w;x++){
			bool ad = true;
			for(int y = 0;y < h;y++) {
				if(mm[x][y] != '.') ad = false;
			}
			if(ad) skipx.insert(x);
		}
	for(int y = 0;y < h;y++){
		bool ad = true;
		for(int x = 0;x < w;x++) {
			if(mm[x][y] != '.') ad = false;
		}
		if(ad) skipy.insert(y);
	}
	for(int y = 0;y < h;y++) {
		if(skipy.find(y) != skipy.end()) continue;
		for(int x = 0;x < w;x++) {
			if(skipx.find(x) != skipx.end()) continue;
			cout << mm[x][y];
		}
		cout << endl;
	}
}
