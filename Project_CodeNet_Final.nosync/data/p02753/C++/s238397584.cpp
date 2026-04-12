#include <iostream>

using namespace std;

int main() {
    char S[5];
    int count=0,i;
    cin >> S;
    for( i=0;i<=2;i++)
    {
        if(S[i] == 'A')
        {
           
            count++;
            
        }

    }

    if(count==3 || count==0)
    {
        cout <<  "No";
    }
    else {
        cout << "Yes";
    }
}