#include <iostream>
#include <string>
using namespace std;

int main() {
    string S ;
    cin >> S ; //Each character of S is A or B.|S|=3 
    if (S[0] == S[1] && S[1] == S[2]) cout << "No" <<endl;
    else cout << "Yes" << endl;
	return 0;
}