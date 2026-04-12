// AtCoder Beginner Contest 174
// A - Air Conditioner

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include <chrono>

using namespace std;
//using namespace std::chrono;


int main()
{
	//steady_clock::time_point start = steady_clock::now();
	int X;

	cin >> X;
	// 制約確認
	if (X < -40 || 40 < X)  {
        cout << "Xは条件を満たしていません!\n";
        return 0;
    }

	if (X >=30) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	//計算時間集計
	/*
	steady_clock::time_point end = steady_clock::now();
    steady_clock::duration d = end - start;
	cout << "計算時間は" << duration_cast<milliseconds>(d).count() << "ミリ秒です。\n";
	*/
}
