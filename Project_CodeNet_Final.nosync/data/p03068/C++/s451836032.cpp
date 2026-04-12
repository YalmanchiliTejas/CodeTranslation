#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

int main(){
    int n,k ;
    string s ;
    cin >> n >> s >> k ;
    char key = s.at(k-1) ;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) != key)
        {
            s.at(i) = '*' ;
        }
        
    }
    cout << s << endl ;
}