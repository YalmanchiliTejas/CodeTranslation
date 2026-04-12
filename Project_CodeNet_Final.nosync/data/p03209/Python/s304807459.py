N, X = map(int, input().split())

L = [0] * (N + 1)
P = [0] * (N + 1)
for i in range(N+1):
    L[i] = 2 ** (i + 2) - 3
    P[i] = 2 ** (i + 1) - 1

def rec(N, X):    

    if X <= 0:
        return(0)
        
    if N == 0:
        return(1)
    
    if X < L[N - 1] + 2:
        return(rec(N - 1, X - 1))
        
    if X == L[N - 1] + 2:
        return(P[N - 1] + 1)
    
    if X > L[N - 1] + 2:
        return(P[N - 1] + 1 + rec(N - 1, X - L[N - 1] - 2))


print(rec(N, X))