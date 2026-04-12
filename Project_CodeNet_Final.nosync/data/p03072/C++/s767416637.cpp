/*O(N)解法 累積max current_maxという変数にそれまでの高さの最大値を格納。.
H[i] と current_max との比較が終わったら、H[i] という値を加味して current_max を再び更新*/
#include <bits/stdc++.h>
using namespace std;
int main()  {
  int N; cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  int res = 0;
  int current_max = 0;
  for (int i = 0; i < N; i++) {
    // i 番目が、i-1 番目以前の最大値以上だったらカウント
    if (H[i] >= current_max) res++;
     // これまでの最大値を新たに更新する
    if (current_max < H[i]) current_max = H[i];
  }
cout << res << endl;
}
/*解説の解法 O(N^2)　入力を配列で受け取り、各 i = 1, 2, ..., N について全ての j = 1, 2, ..., i − 1 に対して Hi ≥ Hj かを確認
し、そうであった i の数を数えることで答えを求めることができる。　　最初こんな感じで考えてたけどうまく実装できなかった。
#include <bits/stdc++.h>
using namespace std;
int main()  {
  int N;
  cin >> N;
  vector<int> a(N);
  int ans = 0;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++)  {
    bool is_candidate = true;
    for (int j = 0; j < i; j++)  {
      if (a[j]>a[i])  {
      is_candidate = false;
      break;
    }
  }
  if(is_candidate) ++ans;
}
cout << ans <<endl;
}*/

/*自分の解法　今考えている番号iより小さい1~i-1についてソートして最大のもの=b[i-1]についてa[i]と比較
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  int ans = 1;
  for (int i = 1; i < N; i++)  {
    vector<int> b(i);
      for (int j = 0; j < i; j++) b[j] = a[j];
    sort(b.begin(), b.end());
    
        if (a[i] >= b[i-1]) ++ans;
  }
  cout << ans << endl;
}
*/