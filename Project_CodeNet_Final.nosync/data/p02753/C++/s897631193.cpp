#include <iostream>
#include <string>

using namespace std;

void A()
{
    string S;
    cin >> S;
    
    if( S[0] == S[1] && S[1] == S[2] ){
        cout << "No" << endl;
        return;
    }
    
    cout << "Yes" << endl;
}

void B()
{
    
}


int main()
{
    A();
    //B();
    
    return 0;
}