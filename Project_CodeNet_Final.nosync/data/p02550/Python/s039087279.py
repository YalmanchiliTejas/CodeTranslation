n, x, m = map(int, input().split())
ans = x
if n <= m:
    for i in range(1, n):
        x = (x * x) % m
        ans += x
    print(ans)
    exit()
cnt = [0] * m
loop = []
start = -1
for i in range(4 * m):
    x = (x * x) % m
    if cnt[x] == 1:
        loop.append(x)
        if start == -1:
            start = i
    cnt[x] += 1
for i in range(m):
    if cnt[i] > 0:
        ans +=  i
l = len(loop)
if l > 0 and start != -1:
    ans += sum(loop) * ((n-1-start) // l)
    ans += sum(loop[:(n-1-start)%l])
print(ans)