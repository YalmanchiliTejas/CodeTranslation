#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    int cnt = 0;
    cin >> s;
    for(int i=0; i<s.length(); i++) cnt += s[i] == 'A';
    cout << ((cnt != 0 && cnt != 3) ? "Yes" : "No") << endl;
    return 0;
}