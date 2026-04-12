n=int(input())
a=list(map(int, input().split()))
ans=0
ruiseki=0
for i in range(n):
    idx = n-1-i
    ans += ruiseki * a[idx]
    ruiseki += a[idx]
    if ans >= 10**9+7:
        ans%=10**9+7

print(ans)
