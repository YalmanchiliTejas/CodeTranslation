N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7
ruisekiwa = [0] * (N + 1)
for i in range(0, N):
    ruisekiwa[i + 1] = ruisekiwa[i] + A[i]
# print(ruisekiwa)
ans = 0
for i in range(N):
    ans += A[i] * (ruisekiwa[N] - ruisekiwa[i + 1]) % MOD
print(ans % MOD)
