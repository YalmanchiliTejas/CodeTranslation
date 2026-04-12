#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    char xin;
    cin >> xin;

    char x[] = {'a', 'e', 'i', 'o', 'u'};
    vector<char> v(x, x+sizeof(x));

    size_t n_count = count(v.begin(), v.end(), xin);
    if(n_count != 0){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }

    return 0;
}
