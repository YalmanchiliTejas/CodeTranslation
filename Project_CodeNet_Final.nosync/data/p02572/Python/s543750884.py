n = int(input())
a = list(map(int, input().split()))
total = sum(a)
mod = 10**9 + 7
ans = 0

for i in range(n - 1):
    total -= a[i]
    ans = (ans + a[i]*total)%mod

print(ans)