#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define PII std::pair<int, int>

class BinaryTree
{
	int* tree, size, initVal;

public:
	BinaryTree(int dataSize, int initVal) : initVal(initVal)
	{
		for (size = 1; size < dataSize; size *= 2);
		tree = (int*)calloc(size * 2, sizeof(int));
		for (int idx = 1; idx < size * 2; idx++)
			tree[idx] = initVal;
	}

	void clear() { free(tree); }

	int decideValue(int x, int y) // Write your function
	{
		return x > y ? x : y;
	}

	void insert(int val, int idx)
	{
		tree[size + idx] = val;
		idx = (idx + size) / 2;
		while (idx)
		{
			tree[idx] = decideValue(tree[idx * 2], tree[idx * 2 + 1]);
			idx /= 2;
		}
	}

	int getValue(int left, int right)
	{
		if (right < left)
			return initVal;
		int ret = initVal;
		left += size;
		right += size;
		while (left <= right)
		{
			if (left % 2 == 1) ret = decideValue(ret, tree[left]);
			if (right % 2 == 0) ret = decideValue(ret, tree[right]);
			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}
		return ret;
	}

	void printTree()
	{
		for (int jump = 2, idx = 1; idx < 2 * size; idx++)
		{
			printf("%d ", tree[idx]);
			if (idx == jump - 1)
			{
				jump *= 2;
				printf("\n");
			}
		}
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> a(n);
	std::vector<PII> d(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		d[i].first = a[i];
		d[i].second = -i;
	}

	std::sort(d.begin(), d.end());

	std::unordered_map<int, int> h;
	for (int i = 0; i < n; i++)
		h[-d[i].second] = i;

	BinaryTree b(n, 0);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int p = h[i];
		int m = b.getValue(0, p - 1);
		if (m == 0) c++;
		else b.insert(0, m - 1);
		b.insert(p + 1, p);
		//b.printTree();
	}

	printf("%d\n", c);

	return 0;
}

