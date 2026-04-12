#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string n = "";
    cin >> n;
    if(n[0] == n[1] && n[1] == n[2]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}