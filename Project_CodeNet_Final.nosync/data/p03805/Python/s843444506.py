from itertools import permutations

def f(n, m, uu, vv):
    a = [[0] *n for _ in range(n)]
    for u, v in zip(uu, vv):
        a[u][v] = 1
        a[v][u] = 1
    res = 0
    for p in permutations(range(n)):
        if p[0] != 0:
            break
        ok = True
        for i in range(n - 1):
            if a[p[i]][p[i+1]] == 0:
                ok = False
                break
        if ok:
            res += 1
    return res

n , m = map(int, input().split())
a = []
b = []
for k in range(m):
    _a, _b = map(int, input().split())
    _a -= 1
    _b -= 1
    a.append(_a)
    b.append(_b)
print(f(n, m, a, b))
