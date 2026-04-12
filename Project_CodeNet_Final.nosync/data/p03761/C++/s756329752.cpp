#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];
    char c = 'a';
    int Now,Min;
    map<char,int> mp;
    while(c <= 'z'){
        Now = 0;
        Min = 51;
        //ｎ個の文字列調査
        for(int i = 0; i < n; i++){
            Now = 0;
            //文字列数え上げ
            for(int j = 0; j < S[i].size(); j++){
                if(S[i][j] == c) Now++;
            }
            Min = min(Min,Now);
        }
        //mapに入力
        mp[c] = Min;
        c++;
    }
    string X = "a";
    for(char i = 'a'; i <= 'z'; i++){
        for(int j = 0; j < mp[i]; j++) X += i;
    }
    sort(X.begin(),X.end());
    for(int i = 1; i < X.size(); i++) cout << X[i];
    cout << endl;
}