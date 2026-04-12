#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
int main() {
    char c;
    string ans;
    cin >> c;
    if(c == 'a'|| c == 'i'|| c == 'u'|| c == 'e'|| c == 'o'){
        ans = "vowel";
    }
    else{
        ans = "consonant";
    }
    cout << ans << endl;
    return 0;
}