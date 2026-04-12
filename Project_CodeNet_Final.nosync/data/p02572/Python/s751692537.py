n = int(input())
a = list(map(int, input().split()))

Sum = 0
for i in range(n):
    Sum += a[i]

ans = 0
for i in range(n):
    Sum -= a[i]
    ans += a[i] * Sum

print(ans % 1000000007)
