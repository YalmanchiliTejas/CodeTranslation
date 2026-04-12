#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    
    if(x == 3) {
        cout << "YES\n"; 
            //\nThe growth of a three-year-old child will be celebrated.\n";
    }
    else if(x == 5) {
        cout << "YES\n";
            //\nThe growth of a five-year-old child will be celebrated.\n";
    }
    else if(x == 7) {
        cout << "YES\n";
            //\nThe growth of a seven-year-old child will be celebrated.\n";
    }
    else cout << "NO\n";
        //See you next year.\n";

    return 0;
}