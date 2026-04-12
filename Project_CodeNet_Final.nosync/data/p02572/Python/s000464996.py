MOD = 10 ** 9 + 7
N = int(input())
A = list(map(int, input().split()))

S = [0] * (N + 1)
for i in range(N):
    S[i + 1] = S[i] + A[i]

SN = S[-1]
ans = 0
for i in range(N - 1):
    a = A[i]
    cnt = a * (SN - S[i + 1])
    ans = (ans + cnt) % MOD
print(ans)
