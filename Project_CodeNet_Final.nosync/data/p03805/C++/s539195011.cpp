#include <bits/stdc++.h>
using namespace std;

struct V {
	int id;
	vector<V*> next;
	V(){}

	V(int i) {
		id = i;
	}
};

struct Path {
	bool completed=false;
	vector<int> visitedVs;
	V* current;

	Path(V* start) {
		current = start;
		visitedVs.push_back(start->id);
	}
	Path(Path* hist, V* cur) {
		current = cur;
		visitedVs = hist->visitedVs;
		visitedVs.push_back(cur->id);
	}

	//未到達の頂点へのパスを返す
	vector<Path*> getNext() {
		vector<Path*> pnext;
		for (V* v : current->next) {
			if (find(visitedVs.begin(), visitedVs.end(), v->id) != visitedVs.end()) {
				continue;
			}
			Path* pn=new Path(this, v);
			pnext.push_back(pn);
		}

		return pnext;
	}
	
};

int main() {
	int N, M;
	cin >> N >> M;
	
	map<int,V*> vertexes;
	for (int i = 0;i < M;i++) {
		int a, b; cin >> a >> b;
		V* vertexA;
		V* vertexB;
		if (vertexes.count(a) == 0) {
			vertexA = new V(a); 
			vertexes[a] = vertexA;
		}
		else {
			vertexA = vertexes[a];
		}
		if (vertexes.count(b) == 0) {
			vertexB = new V(b);
			vertexes[b] = vertexB;
		}
		else {
			vertexB = vertexes[b];
		}

		vertexes[a]->next.push_back(vertexB);
		vertexes[b]->next.push_back(vertexA);
	}

	vector<Path> paths;
	V* vertex = vertexes[1];
	Path path(vertex);
	paths.push_back(path);

	for (int i = 0;i < N - 1;i++) {

		vector<Path> nextPaths;
		for (Path p : paths) {
			auto next = p.getNext();
			for (Path* np : next) {
				nextPaths.push_back(*np);
			}
		}
		paths = nextPaths;
	}

	cout << paths.size() << endl;

	return 0;
}