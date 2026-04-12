#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int mumujun(string s, string temp, int k, int n){
	if (s[k] == 'o'){
		if (temp[k] == 'S' && temp[(k-1+n)%n] == temp[(k+1)%n]){
			return 1;
		}
		if (temp[k] == 'W' && temp[(k-1+n)%n] != temp[(k+1)%n]){
			return 1;
		}
	}
	if (s[k] == 'x'){
		if (temp[k] == 'W' && temp[(k-1+n)%n] == temp[(k+1)%n]){
			return 1;
		}
		if (temp[k] == 'S' && temp[(k-1+n)%n] != temp[(k+1)%n]){
			return 1;
		}
	}

	return 0;

}

int main(void){
	int n;
	string s;

	char zero[2] = {'S', 'W'}, one[2] = {'S', 'W'};


	cin >> n >> s;

	int ok = 0;

	string temp, res;

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			temp = "";
			for (int k = 0; k < n; k++){
				if (k == 0){
					temp += zero[i];
				}
				else if (k == 1)
					temp += one[j];
				else {
					if (s[k-1] == 'o'){
						if (temp[k-1] == 'S')
							temp += temp[k-2];
						else {
							if (temp[k-2] == 'S')
								temp += "W";
							else
								temp += "S";
						}
					}
					else {
						if (temp[k-1] == 'W')
							temp += temp[k-2];
						else {
							if (temp[k-2] == 'S')
								temp += "W";
							else
								temp += "S";
						}
					}
				}

				if (k == n - 1 && ok == 0){
					if (mumujun(s, temp, k, n) && mumujun(s, temp, 0, n))
						ok = 1;

					if (ok == 1){
						res = temp;
					}
				}
			}
		}
	}

	if (ok)
		cout << res << endl;
	else
		cout << -1 << endl;
}