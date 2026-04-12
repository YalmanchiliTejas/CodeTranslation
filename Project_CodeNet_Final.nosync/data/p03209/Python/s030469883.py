N, X = (int(i) for i in input().split())

def Pnum(N, X):
    if N == 0:
        return X
    else:
        if X == 1:
            return 0
        elif 2 <= X <= 2**(N+1) - 2:
            return Pnum(N-1, X-1)
        elif X == 2**(N+1) - 1:
            return Pnum(N-1, 2**(N+1) - 3) + 1
        elif 2**(N+1) <= X <= 2**(N+1) + 2**(N+1) - 4:
            return Pnum(N-1, 2**(N+1) - 3) + 1 + Pnum(N-1, X- (2**(N+1) - 1) )
        elif X == 2 ** (N+2) - 3:
            return 2 * Pnum(N-1, 2**(N+1) - 3) + 1

print(Pnum(N,X))