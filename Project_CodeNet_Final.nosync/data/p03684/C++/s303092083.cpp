#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool used[100010];
vector<pair<int,int>> mp[100010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  pair<pair<int,int>,int> p1[n];
  pair<pair<int,int>,int> p2[n];
  for (int i = 0; i < n; i++) {
    cin >> p1[i].first.first >> p1[i].first.second;
    p1[i].second = i;
    p2[i].first.first = p1[i].first.second;
    p2[i].first.second = p1[i].first.first;
    p2[i].second = i;
  }
  sort(p1, p1+n);
  sort(p2, p2+n);
  for (int i = 1; i < n; i++) {
    int md = abs(p1[i].first.first-p1[i-1].first.first);
    mp[p1[i].second].push_back(make_pair(md,p1[i-1].second));
    mp[p1[i-1].second].push_back(make_pair(md,p1[i].second));
  }
  for (int i = 1; i < n; i++) {
    int md = abs(p2[i].first.first-p2[i - 1].first.first);
    mp[p2[i].second].push_back(make_pair(md,p2[i-1].second));
    mp[p2[i-1].second].push_back(make_pair(md,p2[i].second));
  }

  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  for (int i = 0; i < mp[0].size(); i++) {
    pq.push(mp[0][i]);
  }
  used[0] = 1;
  n--;
  ll ans = 0;
  while (n) {
    pair<int,int> tp = pq.top();
    pq.pop();
    if (used[tp.second]) continue;
    used[tp.second] = 1;
    ans += tp.first;
    n--;
    for (int i = 0; i < mp[tp.second].size(); i++) {
      pq.push(mp[tp.second][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
