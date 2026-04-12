#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int a = 0,b = 0;
    for(const auto &s: input){
        if(s == 'A'){
            a++;
        }else{
            b++;
        }
    }

    if(a != 0 && b != 0){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << std::endl;

    return 0;
}
