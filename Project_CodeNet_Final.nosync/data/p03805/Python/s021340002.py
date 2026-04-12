from itertools import permutations
N, M = map(int, input().split())
ab = [tuple(map(int, input().split())) for i in range(M)]
G = [set() for i in range(N)]

for a, b in ab:
    a -= 1
    b -= 1
    G[a].add(b)
    G[b].add(a)

ans = 0
for x in permutations(range(1, N)):
    if x[0] in G[0]:
        for i in range(N-1):
            if i < N-2:
                if x[i+1] in G[x[i]]:
                    continue
                else:
                    break
            else:
                ans += 1
print(ans)
