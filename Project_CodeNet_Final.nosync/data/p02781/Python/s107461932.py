import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = str(ni() + 1)
m = len(n)
k = ni()


def C(n, k):
    if n < k or n < 0 or k < 0: return 0
    x = 1
    for i in range(k):
        x = x * (n-i)
        x = x // (i+1)
    return x

def p(x, k):
    y = 1
    for i in range(k):
        y *= x
    return y

e = 0
ans = 0
for i in range(m):
    d = ord(n[i]) - ord("0")
    if i == 0:
        if d > 1:
            ans += (d-1)*C(m-1, k-1)*p(9,k-1)
    else:
        ans += 9*C(m-1-i, k-1)*p(9,k-1)
        if d > 0:
            ans += (d-1)*C(m-1-i, k-1-e)*p(9,k-1-e)
            ans += C(m-1-i, k-e)*p(9,k-e)
    if d > 0:
        e += 1
print(ans)
