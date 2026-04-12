n = int(input())
a = list(map(int,input().split()))
ans = 0

#for i in range(n-1):
#    for j in range(i+1,n):
#        ans += a[i]*a[j]
ans = 0
sum_a = 0
for i in range(n):
    ans += a[i]**2
    sum_a += a[i]
tmp = (sum_a ** 2 - ans)//2
print(tmp%(10**9+7))
