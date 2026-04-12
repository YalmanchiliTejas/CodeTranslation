n, x = map(int, input().split())
a, p = [1] * (n + 1), [1] * (n + 1)
for i in range(1, n + 1):
    a[i] = 2*a[i - 1] + 3
    p[i] = 2*p[i - 1] + 1
def f(n, x):
    if n == 0:
        return 1 if x else 0
    if x == 1:
        return 0
    elif 1 < x <= 1 + a[n - 1]:
        return f(n - 1, x - 1)
    elif x == a[n - 1] + 2:
        return p[n - 1] + 1
    elif a[n - 1] + 2 < x <= 2*a[n - 1] + 2:
        return p[n - 1] + 1 + f(n - 1, x - (a[n - 1] + 2))
    elif x == 2*a[n - 1] + 3:
        return 2*p[n - 1] + 1
print(f(n, x))