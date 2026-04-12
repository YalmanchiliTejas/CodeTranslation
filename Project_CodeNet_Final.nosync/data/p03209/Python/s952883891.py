N, X = map(int, input().split())

def rep(N,X):
    if N == 1:
        if X == 1:
            return(0)
        elif X == 5:
            return(3)
        else:
            return(X-1)
    elif X == 1:
        return(0)
    else:
        n = 2**(N+2)-3
        p = 2**N-1 # N-1のPの個数
        if X <= n//2:
            return(rep(N-1, X-1))
        elif X == n//2+1:
            return(p + 1)
        else:
            if n-1 == X-1:
                return(rep(N-1, X-1-n//2-1) + p + 1)
            else:
                return(rep(N-1, X-1-n//2) + p + 1)
print(rep(N,X))
