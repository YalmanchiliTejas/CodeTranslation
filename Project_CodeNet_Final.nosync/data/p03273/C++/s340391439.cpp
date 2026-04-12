#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>

#define ll long long
#define vl vector<ll>
#define vvl vector< vector<ll> >
#define vb vector<bool>
#define vbb vector< vector<bool> >
#define vs vector<string>
#define vc vector<char>
#define vvc vector< vector<char> >

#define all(a) (a).begin(),(a).end()
using namespace std;

bool check(vs &ngo, string s){
	for (string t : ngo) if (t == s) return 0;
	return 1;
}

int main(){
	ll h, w; cin >> h >> w;
	vvc a(h, vc(w));
	vb retuisw(w), gyouisw(h);
	for (int i = 0; i < h; ++i){
		bool t = 1;
		for (int j = 0; j < w; ++j){
			//cout << i << " " << j << endl;
			cin >> a[i][j];
			if (a[i][j] == '#') t = 0;
		}gyouisw[i] = t;
	}
	//cout << "a" << endl;
	for (int i = 0; i < w; ++i){
		bool t = 1;
		for (int j = 0; j < h; ++j){
			if (a[j][i] == '#') t = 0;
		}retuisw[i] = t;
	}
	for (int i = 0; i < h; ++i){
		//cout << gyouisw[i] << endl;
		if (gyouisw[i]) continue;
		for (int j = 0; j < w; ++j){
			if (retuisw[j]) continue;
			cout << a[i][j];
		}cout << endl;
	}
	return 0;
}