n = int(input())
a = list(map(int, input().split()))

total = 0

for i in range(n):
    total = total + a[i]
ts = total * total

iss = 0

for i in range(n):
    iss += a[i] * a[i]
ans = (ts - iss) // 2
print(ans % (10**9 + 7))
