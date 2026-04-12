n = int(input())
a = list(map(int,input().split()))
sum = 0
ans = 0
dp=[]
for i in reversed(range(1,n)):
    sum += int(a[i])
    dp.append(sum % (10**9+7))

for i in range(n-1):
     ans += a[i] * dp[n-2-i]
     ans %= (10**9+7)
print(ans)
