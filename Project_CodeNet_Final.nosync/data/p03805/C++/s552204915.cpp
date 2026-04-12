#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)

 ll MOD = 1000000007;

 int main() {
   int N, M;
   cin >> N >> M;
   vector<vector<int>> Graph(N, vector<int>(N, 0));
   vector<pair<int, int>> input(M);

   rep(i, 0, M) {
     cin >> input.at(i).first >> input.at(i).second;
     input.at(i).first--;
     input.at(i).second--;
     Graph.at(input.at(i).first).at(input.at(i).second)++;
     Graph.at(input.at(i).second).at(input.at(i).first)++;
   }

   vector<int> num;

   rep(i, 1, N) num.push_back(i);

   int cnt = 0;

   do {
     bool ok = true;
     if (!Graph.at(0).at(num.at(0))) ok = false;
     rep(i, 0, N - 2) {
       if (!Graph.at(num.at(i)).at(num.at(i + 1))) ok = false;
     }
     if (ok) cnt++;
   } while (next_permutation(num.begin(), num.end()));

   cout << cnt << endl;
 }
