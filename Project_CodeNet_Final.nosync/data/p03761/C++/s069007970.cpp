#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s[N];
    int minaz[26];
    int tmpaz[26];
    for(int i = 0; i < 26; i++){
        minaz[i] = 100;
        tmpaz[i] = 0;
    }
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    for(int i = 0; i < N; i++){

        for(int j = 0; j < s[i].length(); j++){
            int tmpint = s[i][j] - 'a';
            tmpaz[tmpint]++;
        }
        for(int j = 0; j < 26; j++){
            minaz[j] = min(minaz[j], tmpaz[j]);
            tmpaz[j] = 0;
        }
    }
    for(int i = 0; i < 26; i++){
        if(minaz[i] > 90){
            continue;
        }
        for(int j = 0; j < minaz[i]; j++){
            char tmp = 'a' + i;
            cout << tmp;
        }
    }
    cout << endl;

    return 0;
}