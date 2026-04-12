p = 10**9+7
s = 0
s_sq = 0

N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    s += A[i]
    s_sq += A[i]**2
    s %= p
    s_sq %= p

print((s**2 - s_sq) * pow(2, p-2, p) % p)