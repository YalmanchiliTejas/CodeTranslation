#C - Sum of product of pairs
N = int(input())
A = list(map(int,input().split()))
SUM = 0
jsum= 0
MOD = 1000000007
for j in range(N):
    jsum = (jsum + A[j]) % MOD

for i in range(N-1):
    jsum = (jsum - A[i]) % MOD
    SUM = ( SUM + (jsum * A[i] % MOD ) ) % MOD

# 出力
print(SUM)
