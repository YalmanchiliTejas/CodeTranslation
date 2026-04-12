#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    string s;
    cin >> s;
    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}