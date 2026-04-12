n, x = map(int, input().split())

a, p = [1], [1]
for i in range(n):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def rec(n, x, a, p):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + a[n - 1]:
        return rec(n - 1, x - 1, a, p)
    else:
        return p[n - 1] + 1 + rec(n - 1, x - 2 - a[n - 1], a, p)

ans = rec(n, x, a, p)
print(ans)