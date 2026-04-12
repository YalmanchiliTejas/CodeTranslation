N = int(input())

A = [int(s) for s in input().split()]

MOD = 10**9 + 7
sums = [A[0]]
for a in A[1:]:
    sums.append((a + sums[-1]) % MOD )

alls = 0
for i in range(1, len(A)):
    # print(A[i], sums[i-1])
    alls += A[i] * sums[i-1]
    alls %= MOD
print(alls)