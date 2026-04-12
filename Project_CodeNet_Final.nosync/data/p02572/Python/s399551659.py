N = int(input())
A = list(map(int, input().split()))
m = 10 ** 9 + 7

total = [0] * (N + 1)
for i in range(N):
    total[i + 1] = total[i] + A[i]

total_rev = [0] * (N + 1)
for i in range(N):
    total_rev[i] = total[N] - total[i]

ans = 0
for i in range(N - 1):
    ans = (ans + A[i] * total_rev[i + 1]) % m

print(ans)
