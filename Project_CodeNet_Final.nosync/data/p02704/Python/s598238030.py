from functools import reduce
from operator import and_, or_

N = int(input())
S, T, U, V = [[int(a) for a in input().split()] for _ in range(4)]
X = [[U[i] & V[j] if S[i] and T[j] else U[i] if T[j] else V[j] if S[i] else U[i] | V[j] for j in range(N)] for i in range(N)]

for _ in range(2):
    A1 = [-1] * N
    A2 = [[-1] * N for _ in range(N)]
    for i in range(N-1)[::-1]:
        for j in range(N):
            A2[i][j] = A2[i+1][j] & X[i+1][j]
    for i in range(N):
        if S[i]: a = ~U[i] | reduce(or_, X[i])
        for j in range(N):
            if S[i] and not T[j]:
                X[i][j] |= ~(A1[j] & A2[i][j] | a)
                a |= X[i][j]
            A1[j] &= X[i][j]
    
    if [reduce(or_ if S[i] else and_, x) for i, x in enumerate(X)] != U:
        print(-1)
        exit()
    
    X = [[X[j][i] for j in range(N)] for i in range(N)]
    S, T, U, V = T, S, V, U

for x in X:
    print(*x)