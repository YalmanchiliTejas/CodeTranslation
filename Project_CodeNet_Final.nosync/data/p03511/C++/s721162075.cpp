// ※※※ 解答不能 ※※※
// tourist氏.
// https://atcoder.jp/contests/cf17-relay-open/submissions/8927584
#include <bits/stdc++.h>
using namespace std;

string rep(string s, int k){
    string t = "";
    for(int i = 0; i < k; i++) t += s;
    return t;
}

int main(){
    int L;
    char s[202020], t[202020];
    scanf("%d %s %s", &L, s, t);
    string S(s), T(t);
    int ns = S.size(), nt = T.size();
    string ans = "}";
    for(int i = 0; i * ns <= L; i++){
        if((L - i * ns) % nt == 0){
            int j = (L - i * ns) / nt;
            ans = min(ans, rep(S, i) + rep(T, j));
            ans = min(ans, rep(T, j) + rep(S, i));
            break;
        }
    }
    for(int i = L / ns; i >= 0; i--){
        if((L - i * ns) % nt == 0){
            int j = (L - i * ns) / nt;
            ans = min(ans, rep(S, i) + rep(T, j));
            ans = min(ans, rep(T, j) + rep(S, i));
            break;
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}