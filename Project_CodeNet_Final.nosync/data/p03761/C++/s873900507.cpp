#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++) // for簡略表記
#define DUMP(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) cout << "[" << loop_dump << "]:" << ar[loop_dump] << endl // 配列一覧表示
#define DUMPL(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) { cout << ar[loop_dump]; if(loop_dump<(int)ar.size()-1) cout << ' '; } cout << endl; // 配列一行一覧表示
#define COUT(x) cout << x << endl // 単要素出力
#define ALL(ar) ar.begin(), ar.end() // コンテナの全要素
#define LOOPD(i) cout << "ループ[" << i << "]回目---------------" << endl // ループ回数デバグ
using namespace std;
// cout << fixed << setprecision(4) で小数点以下4桁の桁そろえ
// cout << setw(5) << ... で表示形式を5桁に設定 5桁未満なら頭に空白がつく 5桁越なら先頭から5桁まで
// cout << setw(5) << setfill('0') << ... で空白部分の埋め文字に5を使う
// getline(cin, [変数]); で空白などを含む入力の受け取り(行ごとの受け取り)
// cin >> ws; でそこまでにストリームに残されたホワイトスペースを取り除く(=以降のgetlineの有効化)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    FOR(i, n) cin >> s[i];

    vector<vector<int>> cnt(n, vector<int>(26, 0));
    for(int i=0; i<n; i++){
        for(int k=0; k<(int)s[i].size(); k++){
            cnt[i][s[i][k] - 'a']++;
        }
    }

    vector<pair<int, bool>> ans(26, make_pair(0, true));
    for(int i=0; i<n; i++){
        for(int k=0; k<26; k++){
            if(cnt[i][k] == 0){
                ans[k].second = false;
            }else{
                if(ans[k].first == 0)
                    ans[k].first = cnt[i][k];
                else
                    ans[k].first = min(ans[k].first, cnt[i][k]);
            }
        }
    }

    for(int i=0; i<26; i++){
        if(ans[i].second){
            for(int k=0; k<ans[i].first; k++){
                cout << (char)(i + 'a');
            }
        }
    }
    cout << endl;

    return 0;
}