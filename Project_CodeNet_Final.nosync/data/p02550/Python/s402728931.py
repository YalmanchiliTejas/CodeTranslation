n, x, m = map(int, input().split())
tmp = x
t = [0] * m
cnt = 0
s = 0
while t[x] == 0:
    t[x] += 1
    cnt += 1
    s += x
    x = x * x % m
k = tmp
cnt2 = 0
ans2 = 0
while k != x:
    cnt2 += 1
    ans2 += k
    k = k * k % m
if n <= cnt2:
    s = 0
    x = tmp
    for i in range(n):
        s += x
        x = x * x % m
    print(s)
else:
    n -= cnt2
    s = (s - ans2) * (n // (cnt - cnt2))
    for i in range(n % (cnt - cnt2)):
        s += x
        x = x * x % m
    print(s + ans2)
