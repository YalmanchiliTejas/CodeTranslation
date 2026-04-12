#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <queue>

#define MAX 100005
#define ll long long int
using namespace std;

int main(void) 
{
	ll m; //????????????????????° 
	ll n; //?????¨????????°
	ll sisan;
	ll year;
	vector <ll> th; //????????????????????????
	vector <double> tanhuku;
	vector <ll> tesu;

	int i, j, k;
	vector<ll> ans;
	
	ll temp1, temp3;
	double temp2;
	ll max = 0;
	ll a, b;
	ll zan = 0;

	cin >> m;

	for (i = 0; i < m; i++) {
		max = 0;
		n = 0;
		sisan = 0; 
		year = 0;

		cin >> sisan >> year >> n;



		for (j = 0; j < n; j++) {
			cin >> temp1 >> temp2 >> temp3;
			th.push_back(temp1);
			tanhuku.push_back(temp2);
			tesu.push_back(temp3);


		}


		for (j = 0; j < n; j++) {
			if (th[j] == 0) {
				a = b = 0;

				for (k = 0; k < year; k++) {
					a = sisan - tesu[j] * k;

					b = b + (int)(a * tanhuku[j]);

				}
	
				zan = a - tesu[j];



				if (max < zan + b) {
					max = zan + b;
				}
			}
			else if (th[j] == 1) {
				b = 0;
				a = sisan;

				for (k = 0; k < year; k++) {
					b = (int)(a * tanhuku[j]);
					a = a + b - tesu[j];
				}

				if (max < a) {
					max = a;
				}

			}


		}

		ans.push_back(max);

		th.clear();
		tanhuku.clear();
		tesu.clear();

	}


	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}


	return (0);
}