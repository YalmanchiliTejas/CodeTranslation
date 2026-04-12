#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[5] = {'a', 'e', 'i', 'o', 'u',};
    char c; cin >> c;
    for(int i = 0; i < 5; i++){
        if(c == a[i]){
            puts("vowel");
            return 0;
        }
    }
    puts("consonant");
    return 0;
}