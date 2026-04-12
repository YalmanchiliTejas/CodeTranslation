from itertools import product, permutations,combinations

N, M = map(int, input().split())
rel = [tuple(map(int, input().split())) for i in range(M)]
memo = [[0]*N for i in range(N)]
for r in rel:
        memo[r[0]-1][r[1]-1] = 1
        memo[r[1]-1][r[0]-1] = 1

V = [i+1 for i in range(N)]

cnt = 0
for i in permutations(V, N):
    if i[0] > 1:
        break
        
    for j in range(N-1):
        if memo[i[j]-1][i[j+1]-1] == 0:
            break
    else:
        cnt+=1

print(cnt)