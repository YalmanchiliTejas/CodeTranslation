N, *A = map(int, open(0))
 
A.sort()
 
if N % 2 == 1:
    L, M, R = A[: N//2], A[N//2], A[N//2+1:]
    print((sum(R) - sum(L)) * 2 + max(- M + L[-1], M - R[0]))
else:
    L, R = A[:N // 2], A[N // 2:]
    print((sum(R) - sum(L)) * 2 - R[0] + L[-1])