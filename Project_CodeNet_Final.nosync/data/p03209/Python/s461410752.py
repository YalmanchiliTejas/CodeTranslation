def func(l, u, x, t):
    if len(l) == 0:
        return t+1
    else:
        p = l[-1]
        q = u[-1]
        if x == 1:
            return t
        elif 1 < x <= 1 + p:
            return func(l[:-1], u[:-1], x - 1, t)
        elif x == 2 + p:
            t += u[-1] + 1
            return t
        elif 2 + p < x <= 2 + 2 * p:
            t += u[-1] + 1
            return func(l[:-1], u[:-1], x - (2 + p), t)
        elif x == 3 + 2 * p:
            t += 2 * u[-1] + 1
            return t

n,x  = [int(_) for _ in input().split()]
l = []
for i in range(0, n):
    if i == 0:
        l.append(1)
    else:
        l.append(l[-1]*2+3)
u = []
for j in range(0, n):
    if j == 0:
        u.append(1)
    else:
        u.append(u[-1]*2+1)

print(func(l, u, x, 0))