MOD = 10**9 +7

N = int(input())
A = list(map(int, input().split()))

ans = 0
sumA = 0
sumA_2 = 0
for i in A:
    sumA = (sumA + i) % MOD
    sumA_2 = (sumA_2 + i**2 ) % MOD

ans = (sumA * sumA - sumA_2) % MOD

if ans % 2 == 0:
    print(ans//2)
else:
    print((ans + MOD) // 2)