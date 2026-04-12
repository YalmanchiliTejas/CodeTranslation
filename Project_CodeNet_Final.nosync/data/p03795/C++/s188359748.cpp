#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

	int N;
	int result;
	cin >> N;
    result=N*800-(N/15)*200;
    cout << result << "\n";
}