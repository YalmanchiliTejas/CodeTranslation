from itertools import permutations
n, m = map(int, input().split())
e = [[0] * n for i in range(n)]
v = [i for i in range(1, n)]
for i in range(m):
    a, b = map(int, input().split())
    e[a -1][b - 1] = e[b - 1][a - 1] = 1


ans = 0
for i in permutations(v):
    s = (0,)
    t = s + i
    flag = 1
    for j in range(n - 1):
        if e[t[j]][t[j + 1]] == 0:
            flag = 0
            break
    if flag:
        ans += 1
print(ans)    