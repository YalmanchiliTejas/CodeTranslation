#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    char t[] = {'a','e','i','u','o'};
    char c; cin >> c;

    rep(i,5){
        if(c==t[i]){
            puts("vowel");
            return 0;
        }
    }

    puts("consonant");
    return 0;
}