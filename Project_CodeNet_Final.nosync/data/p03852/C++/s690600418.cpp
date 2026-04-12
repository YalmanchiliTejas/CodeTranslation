#include <iostream>

using namespace std;

int main(){
    
    char c;
    cin >> c;

    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    bool result = false;

    for(auto& t : v){
        if(c == t){
            result = true;
        }
    }

    if(result){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }

}