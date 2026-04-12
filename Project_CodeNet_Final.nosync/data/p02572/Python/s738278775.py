N = int(input())
A = list(map(int, input().split()))
s = sum(A)

ans = 0
for i in range(N - 1):
    s -= A[i]
    ans += A[i] * s

print(ans % (10 ** 9 + 7))
