n, x, m = map(int, input().split())
amr = []
for i in range(n):
    if i == 0:
        x %= m
        amr.append(x)
        continue
    x = pow(x, 2, m)

    if x in amr:
        break
    if x == 0:
        break
    amr.append(x)

if x == 0:
    print(sum(amr[:n]))
else:
    idx = amr.index(x)

    loop = sum(amr[idx:])
    l = len(amr[idx:])

    if n >= idx:
        cnt = (n-idx)//l
        print(cnt*loop + sum(amr[:idx]) + sum(amr[idx:idx+n-idx-cnt*l:]))
    else:
        print(sum(amr[:n]))

