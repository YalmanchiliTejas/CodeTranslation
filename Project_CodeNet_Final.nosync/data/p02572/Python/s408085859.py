n = int(input())
a = list(map(int, input().split()))

sum = 0
for i in range(n):
    sum += a[i]
sum %= 1000000007

ans = 0
for i in range(n):
    sum -= a[i]
    if sum < 0:
        sum += 1000000007
    ans += a[i] * sum
    ans %= 1000000007
print(ans)
