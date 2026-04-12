MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

modS = [0]
for i in A:
    modS.append((modS[-1] + i) % MOD)

ans = 0
for i in range(1, N + 1):
    count = modS[-1] - modS[i]
    if count < 0:
        count = MOD + count
    ans = (ans + (A[i - 1] * count % MOD)) % MOD

print(ans)