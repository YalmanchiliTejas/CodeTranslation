n = int(input())
a = list(map(int,input().split()))

ans = 0
latsum = sum(a)-a[0]
for i in range(n-1):
    ans += a[i]*latsum
    ans %= int(1e9+7)
    latsum -= a[i+1]
        
print(ans)