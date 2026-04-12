n = int(raw_input())
a = [int(x) for x in raw_input().split()]


def f(k):
    s = 0
    for ai in a:
        s += max(0, (ai - (n - 1 - k) + n) // (n + 1))
    return s <= k


lb = 0
ub = 500000000000000001

while lb + 1 < ub:
    mid = (lb + ub) // 2
    if f(mid):
        ub = mid
    else:
        lb = mid

m = lb + 1
i = m - 1
while i >= m - 50:
    if f(i):
        m = i
    i -= 1

print m
