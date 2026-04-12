from numpy import int64

N, A = open(0)
N, A = int(N), int64(A.split())

ans = 0
S = -1
while S:
    B, A = A // N, A % N
    S = B.sum()
    ans += S
    A += S - B

print(ans)
