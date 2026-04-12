#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>

using namespace std;

typedef complex<double> xy_t;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int , P> PP;
typedef pair<int, string> Ps;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF= 1 << 30;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define rep(i, n) for(int i = 0; i < n; i++)

struct data{
	int score;
	int id;
	string name;
	data(){};
	data(int s, int id, string n){
		this->score = s;
		this->id = id;
		this->name = n;
	}
};

bool comp(data d1, data d2){
	return d1.score == d2.score ? d1.id < d2.id : d1.score > d2.score;
}

data ds[10];

int main(){
	int n;
	int w, l, d;
	int cnt = 0;
	while(cin >> n && n){
		if(cnt != 0){
			cout << endl;
		}else{
			cnt++;
		}
		rep(i, n){
			cin >> ds[i].name >> w >> l >> d;
			ds[i].score = w * 3 + d;
			ds[i].id = i;
		}
		sort(ds, ds + n, comp);
		rep(i, n) cout << ds[i].name << "," << ds[i].score << endl;
	}
	return 0;
}