import sys
sys.setrecursionlimit(10000)

N, X = map(int, input().split())

a, p = [1], [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def f(n, x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    med = (a[n]+1) // 2
    if x < med:
        return f(n-1, x-1)
    elif x == med:
        return p[n-1] + 1
    elif x > med:
        return p[n-1] + 1 + f(n-1, x-med)
print(f(N, X))