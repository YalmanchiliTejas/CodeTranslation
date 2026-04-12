N = int(input())
A = list(map(int, input().split()))

sumA, mod, ans = [0], 10 ** 9 + 7, 0
for a in A:
    sumA.append((sumA[-1] + a) % mod)

for i in range(1, N):
    ans = (ans + (sumA[N - i] * A[N - i]) % mod) % mod
print(ans)
