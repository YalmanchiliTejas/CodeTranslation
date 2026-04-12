n = int(input())
a = list(map(int,input().split()))
sum = 0
ans = 0

for i in range(n):
    sum += a[i]

for i in range(n-1):
    sum -= a[i]
    ans += a[i] * sum

print(ans % (10**9 + 7))