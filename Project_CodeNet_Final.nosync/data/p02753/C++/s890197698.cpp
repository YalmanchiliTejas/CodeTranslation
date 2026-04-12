#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string s;
    cin >> s;
    char now=s[0];
    rep(i,2){
        char next=s[i+1];
        if(now!=next){
            puts("Yes");
            return 0;
        }
        now=next;
    }
    puts("No");
    return 0;
}









