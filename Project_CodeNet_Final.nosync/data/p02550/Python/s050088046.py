n, x, m = map(int, input().split())
tt = [i*i % m for i in range(m)]
ss = [i for i in range(m)]


def merge(to1, s1, to2, s2):
    to3 = [to2[to1[i]] for i in range(m)]
    s3 = [s1[i] + s2[to1[i]] for i in range(m)]
    return to3, s3


t = [i for i in range(m)]
s = [0] * m
while n:
    if n % 2 == 1:
        t, s = merge(t, s, tt, ss)
    tt, ss = merge(tt, ss, tt, ss)
    n //= 2

print(s[x])
