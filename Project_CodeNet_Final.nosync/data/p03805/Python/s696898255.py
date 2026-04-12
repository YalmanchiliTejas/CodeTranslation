N, M = map(int, input().split())
ab = [[int(i) for i in input().split()] for j in range(M)]

G = [[] for i in range(N)]
for i in range(M):
    a, b = ab[i]
    G[a-1].append(b-1)
    G[b-1].append(a-1)

def rec(v, memo):
    memo[v] = 1

    if -1 not in memo:
        memo[v] = -1
        return 1

    count = 0
    for next_v in G[v]:
        if memo[next_v] == -1:
            count += rec(next_v, memo)

    memo[v] = -1
    return count

memo = [-1 for i in range(N)]
print(rec(0, memo))