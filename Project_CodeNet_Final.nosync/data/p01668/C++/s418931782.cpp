#include <iostream>
#include <string>
using namespace std;

string A, B, C; long long mod = 1000000007;

string Plus(string V) {
	V[V.size() - 1]++; bool flag = false;
	for (int i = (int)V.size() - 1; i >= 0; i--) {
		if (V[i] <= '9') { flag = true; break; }
		V[i] = '0'; if (i >= 1) { V[i - 1]++; }
	}
	if (flag == false) V = "1" + V;
	return V;
}
string Minus(string V) {
	V[V.size() - 1]--; bool flag = false;
	for (int i = (int)V.size() - 1; i >= 0; i--) {
		if (V[i] >= '0') { flag = true; break; }
		V[i] = '9'; if (i >= 0) { V[i - 1]--; }
	}
	int pos = 0; for (int i = 0; i < V.size(); i++) { if (V[i] != '0') break; pos = i + 1; }
	V = V.substr(pos, (int)V.size() - pos);
	if (V == "") V = "0";
	return V;
}

long long calc(string V) {
	long long res = 0;
	for (int i = 0; i < V.size(); i++) {
		res *= 10LL;
		res += (V[i] - '0');
		res %= mod;
	}
	return res;
}

long long solve(string V) {
	while (V.size() < C.size()) V = "0" + V;

	long long rem = 0;
	for (int i = 0; i <= V.size() - C.size(); i++) {
		string T = V.substr(i, C.size());
		if (T < C) {
			string A = V.substr(0, i); if (A.size() == 0) A = "0";
			for (int j = i + C.size(); j < V.size(); j++) A += "0";

			long long ans = calc(A);
			rem += ans;
		}
		else if (T == C) {
			string A = V.substr(0, i); if (A.size() == 0) A = "0";

			if (C == "0") {
				bool ok = false;
				for (int j = 0; j < A.size(); j++) { if (A[j] != '0') ok = true; }
				if (ok == true) {
					A = Minus(A);

					for (int j = i + C.size(); j < V.size(); j++) A += V[j];
					A = Plus(A);

					long long ans = calc(A);
					rem += ans;
				}
			}
			else {
				for (int j = i + C.size(); j < V.size(); j++) A += V[j];
				A = Plus(A);

				long long ans = calc(A);
				rem += ans;
			}
		}
		else {
			string A = V.substr(0, i); if (A.size() == 0) A = "0"; A = Plus(A);

			if (C == "0") {
				bool ok = false;
				for (int j = 0; j < A.size(); j++) { if (A[j] != '0') ok = true; }
				if (ok == true) {
					A = Minus(A);

					for (int j = i + C.size(); j < V.size(); j++) A += "0";

					long long ans = calc(A);
					rem += ans;
				}
			}
			else {
				for (int j = i + C.size(); j < V.size(); j++) A += "0";

				long long ans = calc(A);
				rem += ans;
			}
		}
		rem %= mod;
	}
	return rem;
}

int main() {
	cin >> A >> B >> C;

	long long V1 = 0; if (A != "0") { V1 = solve(Minus(A)); }
	long long V2 = solve(B); if (A == "0" && C == "0") V2++;
	cout << (V2 - V1 + mod) % mod << endl;
	return 0;
}
