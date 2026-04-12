def AP(N):
    A = [1]
    P = [1]

    for i in range(1,N+1):
        A.append(A[i-1]*2 + 3)
        P.append(P[i-1]*2 + 1)

    return A,P

def count(N, X, A, P):

    if N == 0:
        return 1

    else: # N > 1
        if X == 1:
            return 0

        elif X <= 1 + A[N-1]:
            return count(N-1, X-1, A, P)

        elif X == 2 + A[N-1]:
            return P[N-1] + 1

        elif X <= 2+2*A[N-1]:
            return P[N-1] + 1 + count(N-1, X-2-A[N-1], A, P)

        else:
            return 2*P[N-1]+1


N,X = map(int,input().split())

A, P = AP(N)

ans = count(N,X,A,P)
print(ans)
