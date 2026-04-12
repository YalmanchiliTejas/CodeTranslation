#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.find('A') != std::string::npos){
        if(s.find('B') != std::string::npos){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}