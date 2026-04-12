n,x = map(int, input().split())

p, a = [1], [1]

for i in range(n):
    p.append(p[i]*2+1)
    a.append(a[i]*2+3)

def f(n,x):
    if x <= 0:
        return 0
    else:
        if n <= 0:
            return min(x, 3)
        else:
            if x > a[n]:
                return p[n] + 1 + f(n-1, x-2-a[n])
            elif x == a[n]:
                return p[n]
            else:
                return f(n-1,x-1)

print(f(n,x))