from itertools import permutations

N,M = map(int,input().split())

L = [[False for i in range(N)] for j in range(N)]

for i in range(N) :
    L[i][i] = True
for i in range(M) :
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    L[a][b] = True
    L[b][a] = True

arange = range(2,N+1)

res = 0
for P in permutations(arange) :
    P = [1] + list(P)
    for S,G in zip(P,P[1:]) :
        if not L[S-1][G-1] :
            break
    else :
        res += 1
print(res)
