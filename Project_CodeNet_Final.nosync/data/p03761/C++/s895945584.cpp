#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <iomanip>
using namespace std;
#define MAXSIZE 100005
#define MAXL 100
typedef long long int lli;

const vector<int> reset_vec(26, 0);

int main(){
    vector<int> alphabet_num(26, 50);
    vector<int> alphabet_num_count(26, 0);
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        alphabet_num_count = reset_vec;
        for(int j = 0; s[j] != '\0'; ++j){
            alphabet_num_count[s[j] - 'a']++;
        }

        for(int j = 0; j < 26; ++j){
            alphabet_num[j] = min(alphabet_num[j], alphabet_num_count[j]);
        }
    }

    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < alphabet_num[i]; ++j){
            char c = 'a' + i;
            cout << c;
        }
    }

    cout << endl;
    return 0;
}