from itertools import accumulate

n = int(input())
lis = list(map(int, input().split()))
mod = 10**9 + 7

a = list(accumulate(lis))

ans = 0
for i in range(n-1):
    ans += lis[i] * (a[-1]-a[i])
    ans %= mod

print(ans)