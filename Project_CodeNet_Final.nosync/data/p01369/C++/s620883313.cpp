#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

string s;
string x = "qwertasdfgzxcvb";

int main(){
    while(1){
        cin >> s;
        if(s == "#"){
            break;
        }

        vector<int> v;
        for(char c: s){
            v.push_back(x.find(c) != -1);
        }
        cout << unique(v.begin(), v.end()) - v.begin() - 1 << endl;
    }
    return 0;
}
