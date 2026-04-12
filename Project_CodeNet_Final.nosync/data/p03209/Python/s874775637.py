def dfs(N):
    if N == 0:
        return 1
    component = dfs(N-1)
    tower = 2 * component + 1 
    return tower

N, X = map(int, input().split())
ans = 0
while X > 0:
    for n in range(0, N+1):
        if X < 2**(n+3) - 3 + (N-(n+1)):
            if X > 2**(n+2) - 3 + (N-n):
                ans += dfs(n) + 1 
                X -= 2**(n+2) - 3 + (N-n) + 1
                N = n
            else:
                if n == 0 and X <= N:
                    X = 0
                else:
                    ans += dfs(n)
                    X -= 2**(n+2) - 3 + (N-n)
                    N = n
            break

print(ans)
