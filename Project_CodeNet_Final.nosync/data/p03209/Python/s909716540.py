n, x = map(int, input().split())

a = [1]
p = [1]
for i in range(n):
    a.append(a[-1] * 2 + 3)
    p.append(p[-1] * 2 + 1)

def f(n, x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x <= a[n - 1] + 1:
        return f(n - 1, x - 1)
    else:
        return p[n - 1] + 1 + f(n - 1, x - a[n - 1] - 2)

print(f(n, x))