N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7
sum_A = 0
for i in range(N):
    sum_A = (sum_A + A[i]) % MOD

sum = 0
for i in range(N):
    sum_A = (sum_A - A[i]) % MOD
    sum = (sum + sum_A*A[i]) % MOD 


print(sum)