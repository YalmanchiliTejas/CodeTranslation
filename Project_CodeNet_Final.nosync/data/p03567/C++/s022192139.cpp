#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool check = false;
    for(size_t i = 0; i < s.size() - 1; ++i){
        if(s[i] == 'A' && s[i + 1] == 'C'){
            check = true;
        }
    }

    cout << (check ? "Yes" : "No") << endl;

    return 0;
}