N = int(input())
A = list(map(int, input().split()))

s = 0
for i in range(N):
    s += A[i]

ans = 0
for i in range(N-1):
    s -= A[i]
    p = A[i] * s
    p %= (10 ** 9 + 7)
    ans += p
print(ans%(10 ** 9 + 7))