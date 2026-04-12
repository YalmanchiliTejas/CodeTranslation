#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define ll long long int
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main() {
	int N;
	cin >> N;
	vector<string> arr;

	for(int i = 0; i < N; i++) {
		string input;
		cin >> input;
		arr.push_back(input);
	}
	int freq[26][N];
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < N; j++) {
			freq[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < arr[i].length(); j++) {
			freq[int(arr[i][j]) - int('a')][i]++;
		}
	}

	int overfreq[26];
	for(int i = 0; i < 26; i++) {
		overfreq[i] = 100;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 26; j++) {
			if(overfreq[j] > freq[j][i]) {
				overfreq[j] = freq[j][i];
			}
		}
	}

	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < overfreq[i]; j++) {
			int of_A = int('a');
			int to_output = of_A + i;
			char output = char(to_output);
			cout << output;
		}
	}
	cout << endl;
}
