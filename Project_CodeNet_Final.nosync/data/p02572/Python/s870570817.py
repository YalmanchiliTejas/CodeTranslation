n = int(input())
a = list(map(int,input().split()))

sum1 = 0
sum2 = 0
u = 0
for i in range(n):
    u = a[i]
    sum1 = (sum1+u)%(10**9+7)
    sum2 = (sum2+(u**2))%(10**9+7)

sum1 = sum1**2 % (10**9+7)
ans = (10**9+8)//2 * (sum1-sum2) % (10**9+7)
print(ans)