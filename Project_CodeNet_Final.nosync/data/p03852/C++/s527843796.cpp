#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)


int main(){
    string s = "aeiou";
    char c;
    cin >> c;
    rep(i, 5){
        if(s[i] == c){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}
