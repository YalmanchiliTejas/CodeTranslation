n=int(input())
a=list(map(int,input().split()))
ans=0

s=sum(a)

for i in range(n):
    a1 = a[i]
    s -= a1
    ans += a1*s%(10**9+7)

print(ans%(10**9+7))