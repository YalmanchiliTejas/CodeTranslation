n = int(input())
a = list(map(int, input().split()))

b = 10**9+7
s = sum(a)
ans = 0
for i in range(n-1):
    s -= a[i]
    ans += a[i]*(s%b)
    ans %= b
print(ans)