n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
ans = 0
aa=sum(a)
for i in range(n):
    aa-=a[i]
    ans += a[i]*aa
ans %= mod
print(ans)
