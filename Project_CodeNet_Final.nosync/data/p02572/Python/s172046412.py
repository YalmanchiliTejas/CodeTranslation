MOD = 10 ** 9 + 7

n = int(input())
a = [int(x) for x in input().split()]

sum = 0
for x in a:
    sum += x
    sum %= MOD

ans = 0
for i in range(n):
    sum -= a[i]
    if sum < 0:
        sum += MOD
    ans += a[i] * sum
    ans %= MOD

print(ans)