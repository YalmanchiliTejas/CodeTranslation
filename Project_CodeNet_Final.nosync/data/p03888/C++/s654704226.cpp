#include "iostream"
#include "iomanip"
using namespace std;

double a, b,ans;

int main() {
	cin >> a >> b;
	ans = 1.0 / a + 1.0 / b;
	ans = 1.0 / ans;
	cout <<setprecision(20)<< ans<<"\n";
	return 0;
}