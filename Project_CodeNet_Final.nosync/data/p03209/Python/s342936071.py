g_memo = {0: 1}
h_memo = {0: 1}
dp = {}

def g(l):
    if not l in g_memo:
        g_memo[l] = 3 + 2*g(l-1)
    return g_memo[l]

def h(l):
    if not l in h_memo:
        h_memo[l] = 1 + 2*h(l-1)
    return h_memo[l]

def solve(l, x):
    if x <= 0:
        return 0
    if l == 0: # x > 0
        return 1
    if x >= g(l):
        return h(l)
    if (l, x) in dp:
        return dp[l,x]
    y = 0
    res = 0
    # B
    y += 1
    # f(l-1)
    res += solve(l-1, x-y)
    y += g(l-1)
    # P
    if y < x: # P
        res += 1
    y += 1
    # f(l-1)
    res += solve(l-1, x-y)
    y += g(l-1)
    # B 
    y += 1

    dp[l,x] = res
    return res

n, x = map(int, raw_input().split())
print(solve(n, x))