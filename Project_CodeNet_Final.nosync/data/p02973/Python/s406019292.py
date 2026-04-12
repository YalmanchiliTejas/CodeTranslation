import bisect
N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
A = A[::-1]
S = [A[0]]
c = 1
for i in range(1, N):
    t = A[i]
    if t >= S[-1]:
        S.append(t)
        c += 1
    else:
        p = bisect.bisect_right(S, t)
        S[p] = t
print(c)