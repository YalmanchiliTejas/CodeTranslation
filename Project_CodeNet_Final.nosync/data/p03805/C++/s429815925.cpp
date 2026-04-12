#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <limits>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef std::numeric_limits<double> dbl;
const long long int LL_INF=1LL<<60;

vector<string> split(const string& input, char delimiter)
{
    stringstream stream(input);
    
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

//#define DEBUG

ll A, B, M, N, D, K, Q, W, H, T, X, Y;

vector< pair<int, int> > links;

int dfs(int current, vector<int> visited)
{
    vector<int> next;
    for (auto l : links) {
        int cand;
        if (l.first == current)
            cand = l.second;
        else if (l.second == current)
            cand = l.first;
        else
            continue;
        bool never = true;
        for (auto v : visited)
            if (v == cand) {
                never = false;
                break;
            }
        if (never)
            next.push_back(cand);
    }
    
    if (next.empty())
        if (visited.size() == N)
            return 1;
        else
            return 0;
    else {
        int sum = 0;
        for (auto n : next) {
            vector<int> newVisited;
            for (auto v : visited)
                newVisited.push_back(v);
            newVisited.push_back(n);
            sum += dfs(n, newVisited);
        }
        return sum;
    }
}

int main()
{
    cin >> N >> M;
    links = vector< pair<int, int> >(M);
    for (auto& l : links) {
        cin >> l.first >> l.second;
    }

    cout << dfs(1, {1}) << endl;

    return 0;
}