#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
bool debug = false;
int tmp_iA,tmp_iB;

int main() {
  int N; cin >> N; // 頂点の数（２～８）
  int M; cin >> M; // 辺の数（０～N(N-1)/2)
  set<string> Hen;  // 辺属性を裏表でハッシュにためて、全順列に対し、辿れるか、判定する。
  rep(i,M){
    cin >> tmp_iA >> tmp_iB;
    Hen.insert(to_string(tmp_iA) + '-' + to_string(tmp_iB));
    Hen.insert(to_string(tmp_iB) + '-' + to_string(tmp_iA));
  }
  int Ans = 0; // 最後まで行けるパス数

  // if (debug) {for(auto h:Hen){cout<<h<<endl;}}

  if(N==2){   // ２頂点の場合、1-2 が入ってるかどうかの判断
    if (Hen.count("1-2")) {Ans = 1;}
  } else {    // ３頂点以上（Ｎ≧３）の場合
    // １を起点として、２～Ｎの全順列へのパスの存在チェックを行う。
    // 初期文字列作成
    string Choten;
    rep(i,N-1){ Choten += to_string(i+2); } // ２からＮまでの文字列
    string Check;
    if(debug){for(auto H : Hen) cout << H << endl;}
    do{
      // １から２点目へのパスの有無
      Check = to_string(1) + '-' + (char)(Choten.at(0));
      if (debug) {cout << "A:" << Check << ":" << Hen.count(Check) << endl;}
      if (!Hen.count(Check)) {continue;}  // 1-2 が無ければ、カウントせずに次へ
      rep(i,N-2){
        string Check1; Check1 += Choten.at(i);    // 部分文字列を切り取って、更に繋げるってどうするんだ？
        string Check2; Check2 += "-";
        string Check3; Check3 += Choten.at(i+1);
        Check = Check1 + Check2 + Check3;

        if (debug) {cout << "B:i" << i << " Check:" << Check << " Hen.c:" << Hen.count(Check) << " Choten:" << Choten.at(i) << "-" << Choten.at(i+1) << " Ans:" << Ans << endl;}
        if (!Hen.count(Check)) {break;}  // 1-2 が無ければ、カウントせずに次へ
      }
      if (!Hen.count(Check)) {continue;}  // 1-2 が無ければ、カウントせずに次へ
      Ans +=1; // 最後まで到達したら、パス＋１

    } while (next_permutation(Choten.begin(),Choten.end()));
  }

  cout << Ans << endl;
}