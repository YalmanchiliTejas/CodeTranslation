#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string s[50];
	cin >> n;
	for(int i=0; i<n; i++) cin >> s[i];

	string ans;
	for(int i=0; i<26; i++){
		int cnt[50] = {0};
		for(int j=0; j<n; j++){
			for(int k=0; k<s[j].length(); k++){
				if(s[j][k] == 'a' + i){
					cnt[j]++;
				}
			}
		}
		int cmin = 51;
		for(int l=0; l<n; l++){
			cmin = min(cmin, cnt[l]);
		}
		for(int l=0; l<cmin; l++){
			ans += 'a' + i;
		}
	}

	cout << ans << endl;

    return 0;
}
