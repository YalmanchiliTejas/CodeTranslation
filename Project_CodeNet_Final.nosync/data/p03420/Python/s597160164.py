n, k = map(int, input().split())
ans = 0
for i in range(k+1, n+1):
        d, m = divmod(n, i)
        ans += d*(i-k) + max(0, m-k+1) - (k==0)
print(ans)