#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class t>
using table = vector<vector<t>>;
const ld eps=1e-9;

 //< "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.answer"

enum R_Way {
	R_Left,
	R_Front,
	R_Right,
	R_Back,

	R_Dummy,
};
struct Dice {
	int tp;
	int bo;
	int no;
	int so;
	int ea;
	int we;
	Dice(int tp_, int bo_, int no_, int so_, int ea_, int we_) :
		tp(tp_), bo(bo_), no(no_), so(so_), ea(ea_), we(we_) {

	}
	Dice(vector<int>pips_) {

	}

	Dice() {
		tp = 1;
		/*bo = 6;
		no = 2;
		so = 5;
		ea = 3;
		we = 4;*/
	}
	
	int rotate(const R_Way way) {
		switch (way) {
		case R_Right: {
			int c = tp;
			tp = we;
			we = bo;
			bo = ea;
			ea = c;
		}
					  break;
		case R_Back: {
			int c = tp;
			tp = so;
			so = bo;
			bo = no;
			no = c;
		}
					 break;
		case R_Left: {
			int c = tp;
			tp = ea;
			ea = bo;
			bo = we;
			we = c;
		}
					 break;
		case R_Front: {
			int c = tp;
			tp = no;
			no = bo;
			bo = so;
			so = c;
		}
					  break;
		default:
			assert(false);
		}
		return tp;
	}
	int rotate(const int way) {
		return rotate(static_cast<R_Way>(way));
	}
	void spin(const int left) {
		if (left) {

			rotate(R_Way::R_Left);
			rotate(R_Way::R_Back);
			rotate(R_Way::R_Right);
		}
		else {

			rotate(R_Way::R_Left);
			rotate(R_Way::R_Front);
			rotate(R_Way::R_Right);
		}
	}
	int hash()const {
		return tp + we * 6 + no * 36;
	}
};

int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		map<string, int>mp;
		mp["West"] = 0;
		mp["South"] = 1;
		mp["East"] = 2;
		mp["North"] = 3;
		mp["Right"] = 4;
		mp["Left"] = 5;
		Dice di(1, 6, 5, 2, 3, 4);
		int ans = 0;
		while (N--) {
			string st; cin >> st;
			int type = mp[st];
			if (type < 4) {
				di.rotate(type);
			}
			else {
				di.spin((type - 4));
			}
			ans += di.tp;


		}
		cout << ans+1 << endl;
	}
	
	return 0;
}