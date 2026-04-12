#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define REP(i,k,n) for(int i = k; i < (int)(n); i++)
typedef long long ll;

int main(){
        char c;
        cin >> c;
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
                cout << "vowel" << endl;
        }else{
                cout << "consonant" << endl;
        }
        return 0;
}
