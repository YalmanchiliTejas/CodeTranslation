N, M = map(int, input().split())
g = [[] for i in range(N)]
for i in range(M):
	a, b = map(int, input().split())
	g[a-1].append(b-1)
	g[b-1].append(a-1)

ans = 0
passed = [0]
n = 0
s = [[n,passed]]
while s:
	n, passed = s.pop()
	if len(passed) == N:
		ans += 1
	else:
		for i in g[n]:
			if i not in passed:
				s.append([i, passed + [i]])
print(ans)