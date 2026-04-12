#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	int N;
	cin >> N;
	int freq[26];
    fill(freq, freq + 26, 100);
    while(N--> 0) {
        string input;
        cin >> input;
        for(char c = 'a'; c <= 'z'; c = char(c + 1)) {
            int curr = 0;
            for(auto i : input) if(i == c) curr++;
            freq[c-'a'] = min(freq[c-'a'], curr);
        }
    }
    for(char c = 'a'; c <= 'z'; c = char(c + 1)) {
        while(freq[c-'a']--> 0) {
            cout << c;
        }
    }
    cout << endl;
}