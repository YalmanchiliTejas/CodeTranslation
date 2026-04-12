#include <iostream>
#include <string>
using namespace std;
 
void A()
{
    string S;
    cin >> S;
    
    string answer = "Yes";
    if( S[0] == S[1] && S[1] == S[2] )
        answer = "No";
    
    cout << answer << endl;
}
 
int main()
{
    A();
    return 0;
}