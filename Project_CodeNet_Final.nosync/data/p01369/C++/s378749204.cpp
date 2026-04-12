#include <bits/stdc++.h>
using namespace std;
bool is_left(char c) {
    string left="qwertasdfgzxcvb";
    for(int i=0;i<left.size();i++) if(left[i]==c) return 1;
    return 0;
}
int main() {
    string s;
    while(cin>>s,s!="#") {
        bool L=is_left(s[0]);
        int ans=0;
        for(int i=1;i<s.size();i++) {
            if(L!=is_left(s[i])) {ans++;L^=1;}
        } 
        printf("%d\n",ans);
    }
}