#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    char a;
    cin >> a;
    vector<char> v {'a', 'e', 'i', 'o', 'u'};
    if(find(v.begin(), v.end(), a) != v.end()){
        cout << "vowel";
    }
    else
    {
        cout << "consonant";
    }
    cout << endl;
}
