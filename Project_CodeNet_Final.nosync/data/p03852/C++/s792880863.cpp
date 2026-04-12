#include<iostream>
#include<string>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    char s;
    cin >> s;
    int x = s;
    if (x == 97||x ==101||x ==105||x==111||x ==117) cout<<"vowel\n";
    else cout<<"consonant\n";
}