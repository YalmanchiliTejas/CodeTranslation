l = [1]
p = [1]
N, X = map(int, input().split())
for i in range(N):
    l.append(l[i] * 2 + 3)
    p.append(p[i] * 2 + 1)


def calc(n, x):
    if l[n] <= x:
        return p[n]
    if x == 0 or x == 1:
        return 0
    if x <= l[n] // 2:
        return calc(n - 1, x - 1)
    elif x == l[n] // 2 + 1:
        return p[n - 1] + 1
    else:
        return p[n - 1] + 1 + calc(n - 1, x - (l[n - 1] + 2))

print(calc(N, X))