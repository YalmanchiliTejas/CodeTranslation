MOD = 10 ** 9 + 7
N = int(input())
A = list(map(int, input().split()))
sumA = 0
for ai in A:
    sumA = (sumA + ai) % MOD
ans = 0
for ai in A:
    sumA = sumA - ai
    ans = (ans + sumA * ai) % MOD

print(ans)