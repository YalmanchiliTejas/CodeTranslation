#include<stdio.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define Q 1000000007

// ll white, black;
// vector<vector<char>> c(h, vector<char>(w));
// ll ans = 0;
// vector<ll> a(N);
// const int M = 2;
// void dfs(vector<int> &A) {
//     // 終端条件 --- 10 重ループまで回したら処理して打ち切り
    

//     if(A.size() == h+w){
//       // rep(i, A.size()) cout << A[i];
//       // cout << " ";
//       vector<vector<char>> tmp(h, vector<char>(w));
//       rep(i, h){
//         rep(j, w) tmp[i][j] = c[i][j];
//       }
//       ll cnt = black;
//       for(ll i = 0; i < h; i++){
//         if(A[i] == 1){
//           // cout << i << " ";
//           rep(j, w){
//             if(tmp[i][j] == '#'){
//               tmp[i][j] = 'r';
//               cnt--;
//             }
//           }
//         }
//       }
//       for(ll i = h; i < h+w; i++){
//         if(A[i] == 1){
//           // cout << i << " ";
//           rep(j, h){
//             if(tmp[j][i-h] == '#'){
//               tmp[j][i-h] = 'r';
//               cnt--;
//             }
//           }
//         }
//       }

//       // cout << cnt << endl;
//       if(cnt == k) ans++;
      
//       return;
//     }

//     for (int v = 0; v < M; ++v) {
//         A.push_back(v);
//         dfs(A);
//         A.pop_back(); // これが結構ポイント
//     }
// }

int main(){
  
  ll x;
  cin >> x;

  if(x < 30) cout << "No" << endl;
  else cout << "Yes" << endl;



  return 0;
}