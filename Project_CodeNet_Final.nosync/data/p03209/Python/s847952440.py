n, x = map(int, input().split())

a = [1]
for i in range(1, n+1):
    a.append(2*a[-1]+3)
p = [1]
for i in range(1, n+1):
    p.append(2*p[-1]+1)

def f(n, x):
    if n == 1:
        if x == 1:
            return 0
        elif 2 <= x and x <= 4:
            return x-1
        else:
            return 3
    if x == 1:
        return 0
    elif 1 < x and x <= 1 + a[n-1]:
        return f(n-1, x-1)
    elif x == 2 + a[n-1]:
        return p[n-1] + 1
    elif 2 + a[n-1] < x and x < a[n]:
        return p[n-1] + 1 + f(n-1, x - (2 + a[n-1]))
    else:
        return p[n]
print(f(n, x))