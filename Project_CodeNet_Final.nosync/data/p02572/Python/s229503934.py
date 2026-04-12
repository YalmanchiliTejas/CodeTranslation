n = int(input())
a = list(map(int, input().split()))
s = 0
ans = 0
for i in range(n-1):
    s += a[i]
    ans += s*a[i+1]
    ans = ans%(10**9+7)
print(ans)