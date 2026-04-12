#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<string> S(n);
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		S[i] = tmp;
	}

	map<char, int> hist[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S[i].length(); j++){
			hist[i][S[i][j]]++;
		}
	}

	for(map<char, int>::iterator it = hist[0].begin(); it != hist[0].end(); it++){
		for(int i = 1; i < n; i++){
			it->second = min(it->second, hist[i][it->first]);
		}
	}

	string ans;
	for(map<char, int>::iterator it = hist[0].begin(); it != hist[0].end(); it++){
		for(int i = 0; i < it->second; i++){
			ans.push_back(it->first);
		}
	}

	cout << ans << endl;
	return 0;

	// for(int i = 1; i < n; i++){
	// 	for(map<char, int>::iterator it = hist.begin(); it != hist.end(); it++){
	// 		for(int l = 0; l < it->second; l++){
	// 			bool found = false; /* turn on when it->second is found in S[i]; */
	// 			for(int k = 0; k < S[i].length(); k++){
	// 				/* check if S[i] includes it->second */
	// 				if(S[i][k] == it->second){
	// 					found = true;
	// 					break;
	// 				}
	// 			}
	// 		if(!found) hist[it->first]--;
	// 		}

	// 	}
	// }

	// for(map<char, int>::iterator it = hist.begin())
}