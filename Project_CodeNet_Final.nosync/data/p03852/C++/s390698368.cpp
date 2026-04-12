#include<iostream>
#include<string>

using namespace std;


int main(){
    char c;
    char a[5] = {'a','i','u','e','o'};
    cin >> c;
    bool flag = false;

    for(int i = 0;i<5;i++){
        if( a[i] == c){
            flag = true;
            break;
        }
    }

    if(flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}
