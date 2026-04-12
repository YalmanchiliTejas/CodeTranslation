N = int(input())
lsA = list(map(int,input().split()))
sum1 = sum(lsA)
ans = 0
for i in range(N):
    sum1 = sum1 - lsA[i]
    ans += lsA[i] * (sum1 % (10**9+7))
    ans = ans % (10**9+7)
print(ans)