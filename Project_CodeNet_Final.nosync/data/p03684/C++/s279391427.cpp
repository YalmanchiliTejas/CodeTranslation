#include <algorithm>
#include <stdio.h>
#include <vector>
using ll = long long;
struct Int3
{
	int x, y, z;
	Int3() {};
	Int3(int x, int y, int z) :x(x), y(y), z(z) {};
	bool operator<(const Int3& ano) const {
		if (x != ano.x)
			return x < ano.x;
		if (y != ano.y)
			return y < ano.y;
		return z < ano.y;
	}
	bool operator>(const Int3& ano) const {
		if (x != ano.x)
			return x > ano.x;
		if (y != ano.y)
			return y > ano.y;
		return z > ano.y;
	}
};
template<int _size>
class Union_tree
{
public:
	Union_tree() {
		for (int i = 0; i < _size; i++)
			root[i] = i;
		for (int i = 0; i < _size; i++)
			branchs[i] = 1;
	}
	int find(int node) {
		if (root[node] == node)
			return node;
		return root[node] = find(root[node]);
	}
	void merge(int node1, int node2) {
		int root1 = find(node1), root2 = find(node2);
		if (root1 == root2)
			return;
		branchs[root1] = branchs[root2];
		branchs[root2] = 0;
		root[root2] = root1;
	}
	bool same(int node1, int node2) {
		return find(node1) == find(node2);
	}
	int size(int node) {
		return branchs[find(node)];
	}
private:
	int root[_size], branchs[_size];
};

int main() {
	int	n, x[100000], y[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", x + i, y + i);
	Int3 S[100000];
	for (int i = 0; i < n; i++)
		S[i].x = x[i], S[i].y = i;
	std::sort(S, S + n);

	std::vector<Int3> EDGES;
	for (int i = 1; i < n; i++)
		EDGES.emplace_back(S[i].x - S[i - 1].x, S[i].y, S[i - 1].y);

	for (int i = 0; i < n; i++)
		S[i].x = y[i], S[i].y = i;
	std::sort(S, S + n);

	for (int i = 1; i < n; i++)
		EDGES.emplace_back(S[i].x - S[i - 1].x, S[i].y, S[i - 1].y);

	std::sort(EDGES.begin(), EDGES.end());
	Union_tree<100000> tree;
	int costs = 0;
	for (Int3& s : EDGES) {
		if (tree.same(s.y, s.z))
			continue;
		costs += s.x;
		tree.merge(s.y, s.z);
	}
	printf("%d\n", costs);
}