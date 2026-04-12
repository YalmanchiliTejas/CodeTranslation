from itertools import permutations

N, M = map(int, input().split())
adj = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    adj[a][b] = 1
    adj[b][a] = 1

ans = 0
for seq in permutations(range(1, N + 1)):
    if seq[0] != 1:
        continue
    new = 1
    for i in range(1, N):
        if adj[seq[i - 1]][seq[i]] == 0:
            new = 0
    ans += new
print(ans)
