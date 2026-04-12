// include
#include <iostream>
#include <utility>
#include <list>

// typedef

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)

using namespace std;

int CountPaths(int inNode, list<pair<int, int>> &inPairs, list<int> inNodes);
bool IsVisited(int val, list<int> &inNodes);

int main()
{
  int N, M;
  cin >> N >> M;

  list<pair<int, int>> pairs;
  list<int> nodes;

  REP(index, M)
  {
    int a, b;
    cin >> a >> b;
    pairs.push_back(make_pair(a, b));
    nodes.push_back(a);
    nodes.push_back(b);
  }
  nodes.sort();
  nodes.unique();

  cout << CountPaths(1, pairs, nodes) << endl;

}

int CountPaths(int inNode, list<pair<int, int>> &inPairs, list<int> inNodes)
{
  int count = 0;
  inNodes.remove(inNode);

  if (inNodes.size())
  {
    // pairsを探索
    for (auto pItr = inPairs.begin(); pItr != inPairs.end(); ++pItr)
    {
      // pairの要素と一致があれば実行
      if (inNode == (*pItr).first)
      {
        if (!IsVisited((*pItr).second, inNodes))
        {
          count += CountPaths((*pItr).second, inPairs, inNodes);
        }
      }
      else if (inNode == (*pItr).second)
      {
        if (!IsVisited((*pItr).first, inNodes))
        {
          count += CountPaths((*pItr).first, inPairs, inNodes);
        }
      }
    }
  }
  else 
    return 1;

  return count;
}

bool IsVisited(int val, list<int> &inNodes)
{
  // nodesを探索
  for (auto nItr = inNodes.begin(); nItr != inNodes.end(); ++nItr)
  {
    if (val == *nItr)
      return false;
  }
  return true;
}