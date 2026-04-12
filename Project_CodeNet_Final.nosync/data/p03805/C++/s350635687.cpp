#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int ch(int x){
  if(x < 0){x *= (-1);}
  return x;
}

int main()
{
    // 入力
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n,vector<int>(0));
    for(int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      v[a-1].push_back(b);
      v[b-1].push_back(a);
    }

    // 初期順列
    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i+1;


    // 探索
    
    int cnt = 0;
    do {
      if(order[0] != 1){continue;}
      else{
        int res = 0;
        for(int i = 0; i < n-1; i++){
          if(v[order[i]-1].size() == 0){break;}
          else{
          for(int j = 0; j < v[order[i]-1].size(); j++){
            if(v[order[i]-1][j] == order[i+1]){res++; break;}
          }          
        }
        if(res == n-1){cnt++;}
        }
      }
    } while (next_permutation(order.begin(), order.end()));

    // 答えを出力
    cout << cnt << endl;
}