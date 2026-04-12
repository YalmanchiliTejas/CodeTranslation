n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

ans = 0

sum_j = [0] * n
sum_tmp = 0

for i in reversed(range(n)):
    sum_tmp += a[i]
    sum_j[i] = sum_tmp

for i in range(n-1):
    ans += a[i] * sum_j[i+1] % mod

print(ans % mod)
