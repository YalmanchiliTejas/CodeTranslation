n = int(input())
a = list(map(int, input().split()))

sum = [0 for i in range(n+1)]
for i in range(n - 1, -1, -1):
    sum[i] = sum[i + 1] + a[i]
ans = 0
for i in range(n):
    ans = (ans+(a[i]*sum[i+1])) % 1000000007
print(ans)
