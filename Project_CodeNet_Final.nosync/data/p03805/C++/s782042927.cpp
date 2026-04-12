#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <numeric>
#include <iomanip>
#include <locale>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cmath>

using namespace std;

pair< int, vector< vector<int> > > read();
int think(pair< int, vector< vector<int> > >);
void write(int);

vector< vector<int> > createAdjacencyMatrix(int, vector< vector<int> >);

int main(int argc, char* argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  auto input = read();
  auto output = think(input);
  write(output);

  return 0;
}

pair< int, vector< vector<int> > > read() {
  int n, m, a, b;
  vector< vector<int> > edges;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    edges.push_back(vector<int> {a, b});
  }
  return make_pair(n, edges);
}

int think(pair< int, vector< vector<int> > > input) {
  auto n = input.first;
  auto edges = input.second;
  auto adjacencyMatrix = createAdjacencyMatrix(n, edges);

  auto perm = vector<int>();
  for (int i = 1; i <= n; i++) {
    perm.push_back(i);
  }

  int count = 0;
  do {
    bool found = true;
    for (int i = 0; i < perm.size() - 1; i++) {
      auto from = perm.at(i);
      auto to = perm.at(i + 1);
      if (adjacencyMatrix.at(from).at(to) == 0) {
        found = false;
        break;
      }
    }
    if (found) {
      count++;
    }
  } while (next_permutation(perm.begin() + 1, perm.end())); // + 1 means start vertex is "1" only.

  return count;
}

void write(int output) {
  cout << output << endl;
}

vector< vector<int> > createAdjacencyMatrix(int n, vector< vector<int> > edges) {
  // index 0 is dummy because vertex is 1-indexed.
  auto adjacencyMatrix = vector< vector<int> > (n + 1, vector<int> (n + 1, 0));

  for (auto e : edges) {
    auto from = e.at(0);
    auto to = e.at(1);
    adjacencyMatrix.at(from).at(to) = 1;
    adjacencyMatrix.at(to).at(from) = 1;
  }
  return adjacencyMatrix;
}