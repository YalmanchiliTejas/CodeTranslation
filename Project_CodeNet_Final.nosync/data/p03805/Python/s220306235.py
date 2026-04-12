import itertools

N,M = map(int,input().split())

path = [[False]*N for i in range(N)]
ans = 0

for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    path[a][b] = True
    path[b][a] = True

for i in list(itertools.permutations(range(N),N)):
    if i[0] == 0:
        for j in range(N):
            if j == N-1:
                ans += 1
                break
            if not path[i[j]][i[j+1]]:
                break
print(ans)
