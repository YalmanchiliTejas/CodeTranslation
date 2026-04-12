n = int(input())
a = list(map(int,input().split()))
gou = sum(a)
ans = 0
for i in range(n):
    gou-=a[i]
    ans+=a[i]*(gou)
ans%=10**9+7
print(ans)