n = int(input())
a = list(map(int, input().split()))

sm = sum(a)
ans=0
for i in range(n):
    sm-=a[i]
    ans+=(a[i]*sm)
    ans%=10**9+7

print(ans)