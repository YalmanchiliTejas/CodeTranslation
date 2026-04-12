from itertools import permutations

N,M = map(int,input().split())

Matrix = [[False for x in range(N)] for y in range(N)]
for i in range(N) :
    Matrix[i][i] = True
for i in range(M) :
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    Matrix[a][b] = True
    Matrix[b][a] = True

arange = permutations(range(1,N))
ans = 0
for i in arange :
    pm = [0] + list(i)
    for a,b in zip(pm, pm[1:]) :
        if not Matrix[a][b] :
            break
    else :
        ans += 1
print(ans)
