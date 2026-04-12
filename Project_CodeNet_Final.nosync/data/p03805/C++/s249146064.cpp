#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <math.h>
#pragma warning(disable : 4996)

#define MAX_N 8

int N, M;
int Sum = 0;

struct Node {
	int id;
	std::vector<int> connection;
};

Node Nodes[MAX_N + 1];

bool isVisited(std::vector<int> &visited, int next) {
	for (int i = 0; i < visited.size(); ++i) {
		if (visited[i] == next) return true;
	}
	return false;
}

void refunc(Node &node, std::vector<int> visited) {
	visited.push_back(node.id);
	if (visited.size() == N) {
		++Sum;
		return;
	}
	for (int i = 0; i < node.connection.size(); ++i) {
		int next = node.connection[i];
		if (isVisited(visited, next) == false) {
			refunc(Nodes[next], visited);
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N+1; ++i) {
		Nodes[i].id = i;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		Nodes[a].connection.push_back(b);
		Nodes[b].connection.push_back(a);
	}
	refunc(Nodes[1], std::vector<int>());
	printf("%d", Sum);
	
	return 0;
}
