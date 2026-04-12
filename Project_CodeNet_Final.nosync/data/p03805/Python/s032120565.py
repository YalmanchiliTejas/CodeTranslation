from itertools import permutations

N,M = map(int,input().split())

Matrix = [[False for i in range(N)] for j in range(N)]

for i in range(N) :
    Matrix[i][i] = True
for i in range(M) :
    row,col = map(int,input().split())
    row -= 1
    col -= 1
    Matrix[row][col] = True
    Matrix[col][row] = True

arange = range(2,N+1)

ans = 0
for pm in permutations(arange) :
    pm = [1] + list(pm)
    for row,col in zip(pm,pm[1:]) :
        row -= 1
        col -= 1
        if not Matrix[row][col] :
            break
    else :
        ans += 1
print(ans)
