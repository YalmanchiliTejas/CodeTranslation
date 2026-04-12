n=int(input())
a=list(map(int, input().split()))
suma = sum(a)
ans = 0
for i in range(n):
    suma-=a[i]
    ans+=suma*a[i]
print(ans%(10**9+7))