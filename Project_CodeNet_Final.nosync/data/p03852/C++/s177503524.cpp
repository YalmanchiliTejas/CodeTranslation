#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

int main(void){
    char a[5] = {'a','i','u','e','o'};
    char tmp;
    cin >> tmp;
    for(int i=0;i<5;i++){
        if(tmp == a[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;

    
    return 0;
}