#include <iostream>
#include <string>
using namespace std;
int main() {
    int n=0,f=0,k=0,c=0,d=0,l=0,i=0;
    cin >> n;
    string a[n],out;
    int b[n][26],e[26];
//配列bのリセット(デバッグ用)
    for(i = 0; i < n; i++){
        for(int f = 0; f < 26; f++){
            b[i][f] = 0;
            e[f]=50;
        }}
//S_nへの文字列の代入
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
//S_nからの文字情報の取得
    for(f=0;f<n;f++){
        c = a[f].size();
        for(int l=0;l<c;l++){
            d = (int)(a[f].at(l)) - (int)'a';
            b[f][d] += 1;
        }}
//S_nにおける各配列の最小の取得
    for (i=0; i<26; i++) {
        for (l=0;l<n;l++){
            if (e[i] >= b[l][i]) {
                e[i] = b[l][i];
            }}}
//結果文字列の作成
        for(l=0;l<26;l++){
            for (k=0;k<e[l];k++) {
                out.push_back(97+l);
            }
        }
//結果文字列の出力
   cout << out <<endl;
    return 0;
}
