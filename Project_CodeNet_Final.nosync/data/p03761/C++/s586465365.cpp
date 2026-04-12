#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<string> vec;
    string tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    int ans[26] = {}, size = vec[0].size();
    multiset<char> alphabet;
    // 一つ目の文字列を基準とする
    for(int i=0;i<size;i++)
        alphabet.insert(vec[0][i]);
    char a;
    for(int i=0;i<26;i++){
        a = 'a' + i;
        ans[i] = alphabet.count(a);
    }
    // S2 ~ Sn
    for(int i=1;i<n;i++){
        size = vec[i].size();
        for(int j=0;j<size;j++)
            alphabet.insert(vec[i][j]);
        // アルファベット全探索
        for(int j=0;j<26;j++){
            a = 'a' + j;
            ans[j] = min( ans[j], (int)(alphabet.count(a)) );
        }
        alphabet.clear();   // 忘れない
    }  
    
    // 辞書順に出力
    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++){
            a = 'a' + i;
            cout << a;
        }
    }
    cout << endl;

    return 0;
}