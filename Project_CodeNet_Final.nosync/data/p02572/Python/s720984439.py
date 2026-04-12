n = int(input())

a = list(map(int,input().split()))
ans = 0
s = sum(a)
for i in range(n-1):
    ans += (s - a[i]) * a[i]
    ans %= 10**9+7
    s -= a[i]
print(ans)