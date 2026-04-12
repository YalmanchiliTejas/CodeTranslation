#include<iostream>
using namespace std;

int main(){
    char chara ;
    cin >> chara ;
    if( chara == 'a' || chara == 'e' || chara == 'i' || chara == 'o' || chara == 'u'  )
        cout << "vowel" << endl ;
    else
        cout << "consonant" << endl ;
    return 0;


}