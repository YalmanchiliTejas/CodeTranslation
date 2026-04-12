n, x, m = [int(_) for _ in input().split()]
d = {}
d_rev = {}
d[x] = 0
d_rev[0] = x
c = 0
while True:
    c += 1
    x = (x ** 2) % m
    if x in d:
        roop_idx = d[x]
        break
    else:
        d[x] = c
        d_rev[c] = x

ans = 0
if roop_idx >= n:
    for i in range(n):
        ans += d_rev[i]
    print(ans)
else:
    for i in range(roop_idx):
        ans += d_rev[i]
    roop_num = len(d) - roop_idx
    roop_sum = 0
    for i in range(roop_idx, len(d)):
        roop_sum += d_rev[i]
    ans += ((n-roop_idx)//roop_num) * roop_sum
    roop_last = (n-roop_idx)%roop_num
    for i in range(roop_last):
        ans += d_rev[roop_idx + i]
    print(ans)