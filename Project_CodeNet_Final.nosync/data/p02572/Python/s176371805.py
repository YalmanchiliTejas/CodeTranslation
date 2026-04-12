mod = 10**9+7

x = int(input())

s = list(map(int, input().split()))


def bnp(bs, pw):
    res = 1
    while pw:
        if pw % 2:
            res = (res*bs) % mod
        bs = (bs*bs) % mod
        pw //= 2

    return res


sm = 0
for n in s:
    sm = (sm+n) % mod
sm %= mod

sm = (sm*sm) % mod

sqr = 0

for n in s:
    p = (n*n) % mod
    sqr = (sqr+p) % mod

res = (sm-sqr+mod) % mod
res = (res*bnp(2, mod-2)) % mod

print(res % mod)
