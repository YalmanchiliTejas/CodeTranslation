n = int(raw_input())
a = map(int, raw_input().split())
ans = 0
plus = [0] * n
while True:
    s = 0
    for i in xrange(n):
        ans += a[i] / n
        plus[i] = a[i] / n
        s += a[i] / n
        a[i] -= n * (a[i] / n)
    if s == 0:
        break
    for i in xrange(n):
        a[i] += s - plus[i]
print ans
