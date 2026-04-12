#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char aeiou[5] = {'a','e','i','o','u'};

int main(){
    char c;
    cin >> c;
    for(int i=0;i<5;i++){
        if(c==aeiou[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}