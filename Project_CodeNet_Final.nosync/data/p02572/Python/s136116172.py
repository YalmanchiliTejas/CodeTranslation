MOD = 10**9 + 7

N = int(input())
A = [int(x) for x in input().split()]

sum = 0
squaresum = 0
for i in range(N):
    sum = (sum + A[i]) % MOD
    squaresum = (squaresum + A[i]**2) % MOD
ans = ((sum**2) % MOD - squaresum) % MOD
if ans % 2 == 0:
    print(ans//2)
else:
    print((ans + MOD)//2)