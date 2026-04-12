def dfs(lft, rgt, x, L):
    if x < lft: return 0
    if rgt <= x: return numPs[L]
    mid = (lft + rgt) // 2
    ans = 1 if mid <= x else 0
    ans += dfs(lft + 1, mid - 1, x, L - 1)
    ans += dfs(mid + 1, rgt - 1, x, L - 1)
    return ans

N, X = map(int, input().split())

As, numPs = [1], [1]
for i in range(1, N + 1):
    As.append(As[-1] * 2 + 3)
    numPs .append(numPs[-1] * 2 + 1)

print(dfs(1, As[N], X, N))
