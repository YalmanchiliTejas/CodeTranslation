n = int(input())
a = list(map(int,input().split()))
m = 10**9+7
x = 0
ans = 0
for i in range(n):
    ans+=a[i]*x
    x += a[i]%m
    ans%=m
print(ans)