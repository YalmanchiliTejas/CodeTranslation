N, X, M = map(int, input().split())
A = [X]
S = set()

for i in range(3 * 10 ** 6):
    nx = (A[-1]** 2) % M
    if nx in S:
        break
    S.add(nx)
    A.append(nx)

L = []
R = []
for i, a in enumerate(A):
    if a != nx:
        L.append(a)
    else:
        R = A[i:]
        break

ans = sum(L)
N -= len(L)

RS = sum(R)
ans += RS * (N // len(R))
if R:
    for i in range(N % len(R)):
        ans += R[i]

print(ans)
