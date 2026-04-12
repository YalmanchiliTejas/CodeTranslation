#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k, n;
    char c;
    cin >> n >> s >> k;
    c = s[k-1];
    for(int i = 0; i < s.length(); i++){
        if(s[i] != c){
            putchar('*');
        }
        else{
            putchar(c);
        }
    }
    putchar('\n');
}