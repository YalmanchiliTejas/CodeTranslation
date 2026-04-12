#include<bits/stdc++.h>
using namespace std;

char h[15] = {'a','s','d','f','g','t','r','e','w','q','z','x','c','v','b'};

int isin(char c){
    for(int i=0;i<15;++i){
        if(h[i]==c) return 1;
    }
    return 0;
}

int main(void){
    while(true){
        int cnt = 0;
        char s[40];
        cin >> s;
        if(s[0]=='#') break;
        int prev = isin(s[0]);
        for(int i=1;i<strlen(s);++i){
            int now = isin(s[i]);
            if(now!=prev){
                ++cnt;
                prev = now;
            }
        }
        cout << cnt << endl;
    }
}
