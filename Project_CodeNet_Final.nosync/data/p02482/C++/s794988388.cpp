#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    int a,b;
    cin >> a >> b;
    
    if ( a == b ){
        cout << "a == b" << endl;
    } else if ( a < b ){
        cout << "a < b" << endl;
    } else {
        cout << "a > b" << endl;
    }
    
    return 0;
}