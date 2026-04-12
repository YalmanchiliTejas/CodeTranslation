N, X, M = map(int, input().split())

mods = [0 for _ in range(M)]

x = X
f = False
res = 0
for i in range(N):
    if mods[x]:
        k = i
        l = i + 1 - mods[x]
        f = True
        break
    res += x
    mods[x] = i + 1
    x **= 2
    x %= M

if not f:
    res = 0
    for i in range(M):
        if mods[i]:
            res += i
    print(res)

else:
    x2 = x
    lsm = 0
    for i in range(k):
        if k - l <= i <= k - 1:
            lsm += x
        x **= 2
        x %= M
    loop, r = divmod(N - k, l)
    res += loop * lsm
    for i in range(r):
        res += x2
        x2 **= 2
        x2 %= M

    print(res)