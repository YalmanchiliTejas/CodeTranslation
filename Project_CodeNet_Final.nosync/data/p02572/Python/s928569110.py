n = int(input())
a = list(map(int, input().split()))

ans = 0
m = pow(10, 9)+7
total = sum(a)
for i in range(n-1):
    total -= a[i]
    ans += a[i]%m * total%m
print(ans%m)
