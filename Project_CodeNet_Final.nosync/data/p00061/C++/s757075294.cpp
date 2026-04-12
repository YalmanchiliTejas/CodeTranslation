#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
  vector<pair<int, int> > scores;

  while (1) {
    pair<int, int> score;
    char temp;
    cin >> score.second >> temp >> score.first;
    if (score.first == 0 && score.second == 0) break;
    scores.push_back(score);
  }

  sort(scores.begin(), scores.end(), greater<pair<int, int> >());

  int q;
  while (cin >> q) {
    int rank = 0;
    int lastScore = 0;
    for (int i = 0; i < scores.size(); i++) {
      if (lastScore != scores[i].first) rank++;
      if (q == scores[i].second) break;
      lastScore = scores[i].first;
    }
    cout << rank << endl;
  }
}

