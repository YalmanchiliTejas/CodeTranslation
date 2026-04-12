#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string input_string;
    cin >> input_string;
    for(int i = 0; i < input_string.size()-1; i++) {
        if(input_string[i] == 'A')
            if(input_string[i+1] == 'C'){
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    return 0;
}