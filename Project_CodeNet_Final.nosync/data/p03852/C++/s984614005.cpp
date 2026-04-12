#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;
#define ll long long


int main()
{
    // Value
    string c = "";
    string result;

    // Input
    cin >> c;
    //cin>>N>>x;
    //ll size = 2*N-1;

    // Cal
    if(c=="a" || c=="i" || c=="u" || c=="e" || c=="o"){
        result = "vowel";
    }else{
        result = "consonant";
    }

    // Output
    cout << result << endl;

    // Fin
    return 0;
}