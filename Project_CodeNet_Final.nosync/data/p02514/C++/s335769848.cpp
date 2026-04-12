#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
typedef long long ll;

struct Runner {
	double P, T, B;
	vector<double> Pc;
};

ll triangle[51][51] = { { 0 } };

int main(){
	for(int i = 0; i <= 50; ++i){
		triangle[i][0] = 1;
		for(int j = 1; j <= i; ++j){
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}
	int N, M, L;
	cin >> N >> M >> L;
	vector<Runner> runners;
	for(int i = 0; i < N; ++i){
		int P, T, V;
		cin >> P >> T >> V;
		vector<double> Pc(M + 1);
		for(int j = 0; j <= M; ++j){
			double p = triangle[M][j];
			for(int k = 0; k < j; ++k){ p *= static_cast<double>(P) / 100; }
			for(int k = j; k < M; ++k){ p *= (1.0 - static_cast<double>(P) / 100); }
			Pc[j] = p;
		}
		Runner r = { static_cast<double>(P) / 100, T, static_cast<double>(L) / V, Pc };
		runners.push_back(r);
	}
	ll tsum = 0;
	for(int i = 0; i <= M; ++i){ tsum += triangle[M][i]; }
	cout << setiosflags(ios::fixed) << setprecision(9);
	for(int i = 0; i < N; ++i){
		double result = 0.0;
		for(int j = 0; j <= M; ++j){
			double p = runners[i].Pc[j];
			double t = runners[i].B + runners[i].T * j;
			for(int k = 0; k < N; ++k){
				if(k == i){ continue; }
				double q = 0.0;
				for(int l = M; l >= 0; --l){
					double tt = runners[k].B + runners[k].T * l;
//cerr << l << " => " << tt << " : " << runners[k].Pc[l] << endl;
					if(tt <= t){ break; }
					q += runners[k].Pc[l];
				}
//cerr << i << ", " << j << ", " << k << " => " << q << " : " << t << endl;
				p *= q;
			}
			result += p;
		}
		cout << result << endl;
	}
	return 0;
}