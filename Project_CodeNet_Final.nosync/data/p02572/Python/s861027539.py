MOD = int(1e9 + 7)
n = int(input())
a = list(map(int, input().split()))
sum_a = 0
for i in range(n):
    sum_a += a[i]
    sum_a %= MOD
ans = 0
for i in a:
    sum_a -= i
    ans += sum_a * i % MOD
    ans %= MOD
print(ans)