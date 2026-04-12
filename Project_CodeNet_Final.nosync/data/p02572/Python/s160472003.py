N=int(input())
a=list(map(int,input().split()))
mod = 10**9+7
ruiseki = 0
total=sum(a)
ans = 0
for i in range(N-1):
    ruiseki += a[i]
    ans += a[i] * (total- ruiseki) % mod

print(ans % mod)
