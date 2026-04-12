#include <stdint.h>
#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N >> str;
	unique_ptr<int[]>out = make_unique<int[]>(N);
	//-1 = 未設定,0 = 羊,1 = 狼
	auto check = [&](int v1, int vn)->bool {
		auto pstr = str.data();
		auto ptr = out.get();
		for (size_t i = 0; i < N; i++)
		{
			*ptr = -1;
			ptr++;
		}
		ptr = out.get();
		ptr[N - 1] = vn;
		ptr[0] = v1;
		for (size_t i = 0; i < N - 2; i++)
		{
			bool sim = ptr[i] == 0 ^ pstr[i] == 'x';
			if (sim) {
				ptr[(i + 1)] = ptr[(i + N - 1) % N];
			}
			else {
				ptr[(i + 1)] = (ptr[(i + N - 1) % N] == 0) ? 1 : 0;
			}
		}
		bool sim = ptr[N - 2] == 0 ^ pstr[N - 2] == 'x';
		if (sim) {
			sim = (ptr[N - 3] == ptr[N - 1]);
		}
		else {
			sim = (ptr[N - 3] != ptr[N - 1]);
		}
		if (!sim)return false;
		sim = ptr[N - 1] == 0 ^ pstr[N - 1] == 'x';
		if (sim) {
			return ptr[N - 2] == ptr[0];
		}
		else {
			return ptr[N - 2] != ptr[0];
		}
	};
	auto dout = [&]()->void {
		auto ptr = out.get();
		for (size_t i = 0; i < N; i++)
		{
			cout << ((*ptr == 0) ? 'S' : 'W');
			ptr++;
		}
	};
	bool vout;
	if (vout = check(0, 0)) {
		dout(); }
	else if (vout = check(0, 1)) {
		dout(); }
	else if (vout = check(1, 0)) {
		dout(); }
	else if (vout = check(1, 1)) {
		dout(); }
	else { cout << -1; }

	return 0;
}