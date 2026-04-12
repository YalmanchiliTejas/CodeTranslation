n = int(input())
a = list(map(int,input().split()))
sm = sum(a)
mod = 10**9 + 7
ans = 0
for i in range(n-1):
    ans += a[i]*(sm-a[i])
    sm -= a[i]
    ans = ans%mod
    
print(ans)
