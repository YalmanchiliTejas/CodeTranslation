from numpy import int64

A = int64(open(0).read().split())[1:]
N = len(A)

ans = 0
S = 1
while S:
    S = (A // N).sum()
    ans += S
    A += S - (A // N) * (N + 1)

print(ans)
