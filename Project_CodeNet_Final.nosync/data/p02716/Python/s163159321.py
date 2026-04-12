import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()
a = na()

if n % 2 == 0:
    pre = [0]
    for i in range(0, n, 2):
        pre.append(pre[-1] + a[i])
    suf = [0]
    b = a[::-1]
    for i in range(0, n, 2):
        suf.append(suf[-1] + b[i])
    ans = -99999999999999999
    for i in range(len(pre)):
        ans = max(ans, pre[i] + suf[-1-i])
    print(ans)
else:
    pre = [0]
    for i in range(0, n, 2):
        pre.append(pre[-1] + a[i])
    # pre2 = [0]
    # for i in range(1, n, 2):
    #     pre2.append(pre2[-1] + a[i])
    ans = -999999999999999999
    mx = 0
    for i in range(1, n, 2):
        ans = max(ans, mx + pre[-1] - pre[i//2+1])
        mx = max(mx + a[i], pre[i//2+1])
    ans = max(ans, mx)
    print(ans)
