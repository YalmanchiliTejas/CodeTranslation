n , x = map(int, input().split())
# ABCの長さ
a = [1]
for i in range(n):
    a.append(a[i] * 2 + 3)

# パティの枚数
p = [1]
for i in range(n):
    p.append(p[i] * 2 + 1)

def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x == 1:
        return 0
    elif 1 <  x <=  1 + a[n - 1]:
        return f(n - 1, x - 1)
    elif x == 2 + a[n-1]:
        return p[n-1] + 1
    elif 2 + a[n - 1] < x <= 2 + 2 * a[n - 1]:
        return f(n - 1, x - 2 - a[n - 1]) + p[n-1] + 1
    elif x == 3 + 2 * a[n - 1]:
        return 2 * p[n-1] + 1

print(f(n, x))