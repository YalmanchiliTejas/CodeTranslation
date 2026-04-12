#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
	cin >> n;
    
    string s[n];
    int manag[55][26];
    for (int i = 0; i < 55; i++){
        for (int j = 0; j < 26; j++){
            manag[i][j] = 0;
        }
    }

    int mins[26];
    for (int i = 0; i < 26; i++){
        mins[i] = 100;
    }

    string b;
    for (int i = 0; i < n; ++i){
		cin >> b;
        for (int j = 0; j < b.size(); j++){
            manag[i][b[j] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < n; j++){
            mins[i] = min(mins[i], manag[j][i]);
        }
    }

    string moji;
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < mins[i]; j++){
            if(mins[i]>0){
                moji += 'a' + i;
            }
        }
    }
    if(!moji.empty()){
        cout << moji << endl;
    }else{
        cout << "" << endl;
    }
}