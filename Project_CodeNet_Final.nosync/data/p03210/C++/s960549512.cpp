#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

unsigned long long int a = 0, b = 0, c = 100, d = 0, e = 0, n = 0, maxy = 0, min = 0, ans = 0, counter = 0, sur = 0;
std::vector<unsigned long long int> vec{}, vecniki{};
int yoko = 0, tate = 0;
int arraykun[2300] = {}, nyan[200] = {}, koji[50][50];
std::string output, output2, output3, input;
int kakunou[50][50] = { 53 }, moji[50];
bool okada = false, sink = false, backsink = false;
char one, two;
int dp(int i, int j) {
	bool okada = true;
	if (i == 0 || j == 0) {
		okada = false;
		return 0;
	}
	if (koji[i][j] == -1) {
		okada = false;
		return 0;
	}
	if (i == 1 && j == 1) {
		okada = false;
		return 1;
	}
	if (okada) {
		return dp(i - 1, j) + dp(i, j - 1);
	}

}
int main()
{

	cin >> a;
	if (a == 3 || a == 5 || a == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}




