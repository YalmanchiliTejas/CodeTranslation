import itertools
na = lambda: list(map(int, input().split()))

n, m = na()
t = [[0] * 10 for _ in range(10)]
for _ in range(m):
    a, b = na()
    a -= 1
    b -= 1
    t[a][b] = t[b][a] = 1

ans = 0
for l in itertools.permutations(range(n)):
    if l[0]: continue
    flag = 1
    for i in range(1, n):
        if t[l[i]][l[i-1]] == 0:
            flag = 0
            break
    if flag:
        ans += 1

print(ans)