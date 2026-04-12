from itertools import permutations
N, M = map(int, input().split())
edge = []
for _ in range(M):
    a, b = map(int, input().split())
    edge.append(set((a, b)))

p = list(map(lambda x: [1] + list(x), permutations([i for i in range(2, N + 1)])))

ans = 0

for root in p:
    for i in range(len(root) - 1):
        if not set((root[i], root[i + 1])) in edge:
            break
    else:
        ans += 1

print(ans)
