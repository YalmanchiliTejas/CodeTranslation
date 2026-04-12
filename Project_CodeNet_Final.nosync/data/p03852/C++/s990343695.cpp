#include <bits/stdc++.h>    //C++の標準ライブラリのヘッダを全て読み込む
 
int main() {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;

    char c;
    cin >> c;
 
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}