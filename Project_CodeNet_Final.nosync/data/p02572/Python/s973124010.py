n = int(input())
a = list(map(int, input().split()))
total = 0
MOD = 10**9+7
back= sum(a)

for i in range(n-1):
    back -= a[i]
    total += a[i] * back
    total = total % MOD
print(total)