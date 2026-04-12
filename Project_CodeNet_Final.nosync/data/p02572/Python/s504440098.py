import sys

MOD = 10**9 + 7

n = int(input())

a = list(map(int, input().split()))

x = pow(sum(a), 2)
y = sum((a[i]**2 for i in range(n)))

sum = (x - y) // 2 % MOD

print(sum)
