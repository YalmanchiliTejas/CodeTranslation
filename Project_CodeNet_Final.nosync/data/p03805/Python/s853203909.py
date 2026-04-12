N, M = map(int, input().split())
edges = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a] += [b]
    edges[b] += [a]
candy = [[1]]
for _ in range(N - 1):
    tmp = []
    for c in candy:
        for next in edges[c[-1]]:
            tmp += [c + [next]]
    candy = tmp
print(sum(len(set(c)) == N for c in candy))