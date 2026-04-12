n = int(input())
a = list(map(int,input().split()))
sums = [a[n-1]]
for i in range(n-2,0,-1):
    sums.append(sums[len(sums)-1]+a[i])
sums = sums[::-1]
mod = 10**9+7
ans = 0
for i in range(n-1):
    ans += a[i]*sums[i]
    ans %= mod
print(ans)