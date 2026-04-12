n = int(input())
a = list(map(int, input().split()))

ans = 0
mod = 1000000007

a = [-1] + a
pre = [0]

for i in range(1, n+1):
    pre.append((pre[i-1] + a[i]) % mod)
pre.append(0)

for i in range(1, n+1):
    now = (pre[n] - pre[i]) * a[i] % mod
    ans = (ans + now) % mod

print(ans)