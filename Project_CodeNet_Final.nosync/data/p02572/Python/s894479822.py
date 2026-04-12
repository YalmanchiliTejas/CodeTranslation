N = int(input())
A = [int(a) for a in input().split()]

ans = 0
current = 0
for j in range(N):

    if j != 0:
        current += A[j - 1]

    ans += A[j] * current

ans %= (10 ** 9 + 7)
print(ans)