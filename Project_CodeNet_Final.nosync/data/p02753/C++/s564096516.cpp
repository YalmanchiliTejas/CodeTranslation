#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    for (size_t i = 0; i < s.size()-1; i++)
    {
        if (s.at(i) != s.at(i+1))
        {
            cout << "Yes" << endl ;
            return 0;
        }
        
    }
    cout << "No" << endl ;
}