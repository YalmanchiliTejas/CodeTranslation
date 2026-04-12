n = int(input())
a = [int(_) for _ in input().split()]
b = [0 for i in range(n+1)]

for i in reversed(range(n)):
    b[i] += a[i]+b[i+1]

ans = 0

MOD = 10**9+7

for i in range(n-1):
    ans = (ans+a[i]*b[i+1]) % MOD

# print(a, b)

print(ans)
