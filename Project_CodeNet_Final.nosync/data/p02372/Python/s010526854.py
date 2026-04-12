from collections import deque


def bfs(n, adj, source):
	dist = [-1] * n
	dist[source] = 0
	q = deque([source])
	mx = 0
	idx = 0
	while q:
		cur = q.popleft()
		for nxt, d in adj[cur]:
			if dist[nxt] < 0:
				dist[nxt] = dist[cur] + d
				if dist[nxt] > mx:
					mx = dist[nxt]
					idx = nxt
				q.append(nxt)
	return idx, mx, dist


def main():
	n, *L = map(int, open(0).read().split())
	adj = [[] for _ in range(n)]
	for a, b, c in zip(*[iter(L)] * 3):
		adj[a].append((b, c))
		adj[b].append((a, c))
	idx1, _, _ = bfs(n, adj, 0)
	idx2, _, dist1 = bfs(n, adj, idx1)
	idx3, _, dist2 = bfs(n, adj, idx2)
	ans = [max(x, y) for x, y in zip(dist1, dist2)]
	print("\n".join(map(str, ans)))


if __name__ == '__main__':
	main()

