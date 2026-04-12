#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    map<char, int> m;
    for(char c: str){
        m[c]++;
    }
    if(m.size() == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}