MOD = int(1e9+7)

N = int(input())
A = list(map(int, input().split()))

dot = sum(A)**2 % MOD
diag = sum(a**2 % MOD for a in A)
answer =  (dot - diag) * pow(2, -1, MOD) % MOD

print(answer)
