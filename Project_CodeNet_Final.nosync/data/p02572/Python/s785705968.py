N = int(input())
MOD = 10**9 + 7

A = list(map(lambda x: int(x)%MOD, input().split()))
S = []

tmp_s = 0
for A_i in A[::-1]:
    tmp_s += A_i
    S.append(tmp_s%MOD)
S.pop(-1)
S = S[::-1]

ans = 0
for i in range(N-1):
    ans += (A[i] * S[i])%MOD
    ans = ans%MOD
print(ans)