#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;
    if (X >= -40 && X <= 40 ){
        if(X >= 30){
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
        
    
}