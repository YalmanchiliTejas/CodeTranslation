n = int(input())
dat = []
for _ in range(n):
    dat.append(int(input()))
dat.sort()
# 1 2 3 4 5
# 1 2 3 4

if n & 1 == 0:
    x1 = n // 2
    x2 = x1 - 1
    res = 0
    for i in range(n):
        if i < x2:
            res += (dat[i]) * -2
            continue
        if i == x2:
            res += (dat[i]) * -1
            continue
        if i == x1:
            res += (dat[i])
            continue
        if i > x1:
            res += (dat[i]) * 2
            continue
    print(res)
else:
    xc = n // 2
    xl = xc - 1
    xr = xc + 1

    res = 0
    for i in range(n):
        if i < xl:
            res += (dat[i]) * -2
            continue
        if i == xl:
            res += (dat[i]) * -1
            continue
        if i == xc:
            res += (dat[i]) * -1
            continue
        if i > xc:
            res += (dat[i]) * 2
            continue

    res2 = 0
    for i in range(n):
        if i < xc:
            res2 += (dat[i]) * -2
            continue
        if i == xc:
            res2 += (dat[i]) * 1
            continue
        if i == xr:
            res2 += (dat[i]) * 1
            continue
        if i > xr:
            res2 += (dat[i]) * 2
            continue

    print(max(res, res2))

