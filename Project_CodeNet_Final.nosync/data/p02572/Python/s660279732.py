n = int(input())
a = list(map(int, input().split()))
sum_a = sum(a)
ans = 0
mod = 10**9 + 7

for i in range(n):
    sum_a -= a[i]
    ans += a[i] * sum_a
    ans %= mod
print(ans)
