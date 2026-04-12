#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while (1){
	int n;
	vector<int> s;
	
	cin >> n;
	if (n == 0) break;
	int t;
	for (int i = 0; i < n; i++){
	    cin >> t;
	    s.push_back(t);
	}
	sort(s.begin(), s.end());

	int score = 0;
	for (int i = 1; i < s.size() - 1; i++){
	    score += s[i];
	}
	score /= s.size() - 2;

	cout << score << endl;
    }
}