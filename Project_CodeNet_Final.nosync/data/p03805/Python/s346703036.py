n, m = map(int, raw_input().split())
E = [[0]*n for i in xrange(n)]

for i in xrange(m):
    a, b = map(int, raw_input().split())
    E[a-1][b-1] = E[b-1][a-1] = 1

memo = {}
def dfs(state, v):
    if state == 0:
        return v == 0
    if (state, v) in memo:
        return memo[state, v]
    res = 0
    for i in xrange(n):
        if E[v][i] and (state >> i) & 1 == 1:
            res += dfs(state ^ (1 << i), i)
    memo[state, v] = res
    return res

print sum(dfs((2**n-1) ^ (1 << i), i) for i in xrange(n))
