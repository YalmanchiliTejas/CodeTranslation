n, x = (int(i) for i in input().split())

a, p = [1], [1]
for i in range(n):
    a.append(a[-1]*2+3)
    p.append(p[-1]*2+1)

def f(n, x):
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif 1 < x <= a[n-1]+1:
        return f(n-1, x-1)
    elif x == a[n-1]+2:
        return p[n-1] + 1
    elif a[n-1] + 2 < x <= a[n-1]*2 + 2:
        return p[n-1] + f(n-1, x-a[n-1]-2) + 1
    elif x == a[n-1]*2 + 3:
        return p[n-1]*2 + 1

print(f(n,x))