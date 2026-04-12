#include <iostream>
#include <vector>
#include <string>

#define rep(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main(){
    string station;
    cin >> station;
    //string company = station[0];
    string out = "No";
    for (int i = 1; i < 3; ++i)
    {
        if(station[i] != station[0])
            out = "Yes";
    }
    cout << out << endl;
    return 0;
}