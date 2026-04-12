N = int(input())
A = tuple(map(int, input().split()))
MOD = 10 ** 9 + 7

Acc = [0] * N
Acc[0] = A[0]
for i in range(1, N):
    Acc[i] = (Acc[i - 1] + A[i]) % MOD

ans = 0
for i in range(N - 1):
    ans = (ans + Acc[i] * A[i + 1]) % MOD
print(ans)
