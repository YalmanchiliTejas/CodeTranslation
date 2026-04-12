#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    if (s.find("AC") != -1) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;        
    }
}
