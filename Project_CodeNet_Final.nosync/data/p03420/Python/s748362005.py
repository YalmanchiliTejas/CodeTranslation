import numpy as np

n, k = map(int, input().split())
ans = 0
for m in range(k, n):
    nm = n - m
    sb = m + 1
    s = nm // sb
    p = s + 1 if m else s
    ps = sb
    for d in range(s, 0, -1):
        ds = nm // d + 1
        co = ds - ps
        ans += co * p
        ps = ds
        p -= 1
    ans += n + 1 - ps

    # ds = [nm // d + 1 for d in range(s, 0, -1)]
    # ds = [sb] + ds + [n + 1]
    # # print(m, nm, sb, s, ds)
    # dd = np.diff(ds)
    # pd = np.arange(s + 1, 0, -1) if m else np.arange(s, -1, -1)
    # # print(dd, pd, dd * pd, sum(dd * pd))
    # ans += sum(dd * pd)
print(ans)
