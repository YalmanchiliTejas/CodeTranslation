n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(1, n+1):  a[i] += a[i-1]
ans, m = 0, int(1e9+7)
for i in range(1, n):
    ans = (ans + (a[i]-a[i-1])*(a[n]-a[i])) % m

print(ans)
