def f(i):
    global ans
    if i == n - 1:
        if G[0][s[0]] == 0:
            return
        t = sorted(s)
        for j in range(n - 2):
            if t[j] == t[j + 1]:
                return
        for j in range(n - 2):
            if G[s[j]][s[j + 1]] == 0:
                return
        ans += 1
        return
    for j in range(n - 1, 0, -1):
        f(i + 1)
        s[i] = j

n, m = map(int, input().split())
G = [[0 for _ in range(n)] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    G[a - 1][b - 1] = 1
    G[b - 1][a - 1] = 1
s = [1] * (n - 1)
ans = 0
f(0)
print(ans)