# C - Sum of product of pairs
N = int(input())
A = list(map(int,input().split()))
MOD = 10**9+7
sum1 = sum(A)
sum2 = 0
for a in A:
    sum2 += a**2
ans = (sum1**2-sum2)//2
ans %= MOD
print(ans)