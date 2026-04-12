N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(N):
    a.append(2 * a[-1] + 3)
    p.append(2 * p[-1] + 1)


def f(n, x):
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0
    elif x < a[n-1] + 2:
        return f(n-1, x-1)
    elif x == a[n-1] + 2:
        return p[n-1] + 1
    elif x < 2 * a[n-1] + 3:
        return f(n-1, x-a[n-1]-2) + p[n-1] + 1
    else:
        return p[n]

print(f(N, X))