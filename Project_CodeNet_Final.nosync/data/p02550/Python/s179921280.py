n, x, m = map(int, input().split())
nxt = [-1] * m
now = x
while nxt[now] == -1:
    nxt[now] = now * now % m
    now = nxt[now]
junction = now
ans = x
now = x
n = n - 1
while n and now != junction:
    now = nxt[now]
    n -= 1
    ans += now
if n == 0:
    print(ans)
    exit()

llen = 1
lsum = junction
now = nxt[junction]
while now != junction:
    llen += 1
    lsum += now
    now = nxt[now]
ans += lsum * (n // llen)
n = n % llen

now = junction
while n:
    now = nxt[now]
    n -= 1
    ans += now
print(ans)