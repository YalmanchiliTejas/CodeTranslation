#include <iostream>
using namespace std;

// 入力された文字cが母音か子音かを判定するプログラム
// 母音ならvowel、子音ならconsonantと出力する
// >> a
// vowel
// >> z
// consonant
// >> s
// consonant
int main() {
    char c;
    cin >> c;

    bool isVowel = (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');

    if(isVowel)
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}