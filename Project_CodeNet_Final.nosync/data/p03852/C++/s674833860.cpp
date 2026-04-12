#include <iostream>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    char c;
    cin >> c;
    char aeiou[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; ++i){
        if(c == aeiou[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
