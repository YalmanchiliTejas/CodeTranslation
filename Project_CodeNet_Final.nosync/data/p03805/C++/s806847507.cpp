
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <queue>

using namespace std;

#define ll long long

class Main {
public:
	int rec(int n, vector<pair<int, int> >& edges, vector<bool>& prevs, int last) {
		bool isCleared = true;
		for (int i = 0;i < prevs.size();i++) {
			isCleared &= prevs[i];
		}
		if (isCleared) {
			return 1;
		}

		int sum = 0;
		for (int i = 0;i < edges.size();i++) {
			auto edge = edges[i];
			int v = last;

			if (edge.first == v || edge.second == v) {
				int u = (edge.first == v ? edge.second : edge.first);

				if (prevs[u]) continue;

				prevs[u] = true;
				sum += rec(n, edges, prevs, u);
				prevs[u] = false;
			}
		}

		return sum;
	}

	int getNum(int n,vector<pair<int, int> >& edges, int start){
		vector<bool> prevs(n, false);
		prevs[start] = true;

		return rec(n, edges, prevs, start);
	}
};


int main()
{
	Main main;
	int n;
	int en;
	vector<pair<int, int> > edges;

	cin >> n >> en;
	for (int i = 0;i < en;i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> p(a-1, b-1);
		edges.push_back(p);
	}

	cout << main.getNum(n, edges,0) << endl;
    return 0;
}

