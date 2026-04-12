n = int(input())
a = list(map(int,input().split()))
m = sum(a)
ans = 0
for i in range(n-1):
    m -= a[i]
    ans += a[i] * m
    ans %= 10 ** 9 + 7
print(ans)