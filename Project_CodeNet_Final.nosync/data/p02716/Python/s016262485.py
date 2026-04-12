n = int(input())
a = [int(i) for i in input().split()]

if n // 2 == 1:
    print(max(a))
    exit()
if n < 20:
    d = a.copy()
    
    for i in range(1, n // 2):
        b = [0] * n
        c = -10 ** 24
        ans = -10 ** 24
        for j in range(i * 2, n):
            c = max(c, a[j - 2])
            b[j] = c + d[j]
            ans = max(ans, c + d[j])

        a = b.copy()
    print(ans)
    exit()

b = a[:10]
e = [True]*10

for i in range(1, n // 2):
    c = [0] * 10
    f = [False]*10
    d = -10**24
    for j in range(10):
        if 2 * i + j >= n:
            continue
        if not e[j]:
            continue
        d = max(d, b[j])
        c[j] = d + a[2 * i + j]
        f[j] = True
    e = f.copy()
    b = c.copy()
ans = -10 ** 24
for i in range(10):
    if e[i]:
        ans = max(ans, b[i])
print(ans)
