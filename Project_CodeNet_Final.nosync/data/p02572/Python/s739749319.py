n = int(input())
a = list(map(int,input().split()))
b = sum(a)
m = 10**9 + 7
ans = 0
for i in range(n):
    b -= a[i]
    ans += a[i]*b % m
    ans %= m
print(ans)