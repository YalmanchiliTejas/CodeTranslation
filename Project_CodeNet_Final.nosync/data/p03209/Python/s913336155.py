N, X = map(int, input().split())
a = [1]
for _ in range(N - 1):
    a.append(a[-1] * 2 + 3)
p = [1]
for _ in range(N - 1):
    p.append(p[-1] * 2 + 1)
# print(a)
# print(p)
def func(n, x):
    if n == 0 and x == 1:
        return 1
    if x == 1:
        return 0
    elif x <= 1 + a[n - 1]:
        return func(n - 1, x - 1)
    elif x == 2 + a[n - 1]:
        return p[n - 1] + 1
    elif x <= 2 + a[n - 1] * 2:
        return p[n - 1] + 1 + func(n - 1, x - a[n - 1] - 2)
    else:
        return p[n - 1] * 2 + 1

print(func(N, X))
